/**@file   repair/src/main.c
 * @brief  repair algorithm with reoptimization
 * @author Arthur Feng
 */

#include <stdio.h>
#include <string.h>

#include "scip/scip.h"
#include "scip/scipdefplugins.h"
#include "scip/scip_reader.h"

/** main method */
int
main(
        int                   argc,             /**< number of arguments from the shell */
        char**                argv              /**< array of shell arguments */
        )
{   
   SCIP* scip = NULL;
   SCIP_RETCODE retcode;

   if (argc != 4)
   {
      printf("There must exist 3 arguments:\"solution s^0\", \" new problem p^1\", and a integer number k \n\n");
      return 1;
   } 

   /*********
    * Setup *
    *********/

   /* initialize SCIP */
   SCIP_CALL( SCIPcreate(&scip) );

   /***********************
    * Version information *
    ***********************/
   SCIPprintVersion(scip, NULL);
   SCIPinfoMessage(scip, NULL, "\n");
   
   /* include default SCIP plugins */
   SCIP_CALL( SCIPincludeDefaultPlugins(scip) );

   /********************
    * Problem Creation *
    ********************/
   SCIPinfoMessage(scip, NULL, "read problem <%s> ...\n\n", argv[1]);
   SCIP_CALL( SCIPreadProb(scip, argv[1], NULL) );
   SCIP_CALL( SCIPprintOrigProblem(scip,NULL,NULL,TRUE) );
//    SCIP_CALL( SCIPprintTransProblem(scip,NULL,NULL,TRUE) );

   /********************
    * Read Solution *
    ********************/
   SCIP_SOL* sol = NULL;
   SCIP_Bool partial = FALSE;
   SCIP_Bool error = FALSE; 
   SCIPinfoMessage(scip, NULL, "read solution <%s> ...\n\n", argv[2]); 
   SCIP_CALL( SCIPcreateSol(scip,&sol,NULL) );
   SCIP_CALL( SCIPreadSolFile(scip,argv[2],sol,FALSE,&partial,&error)); 




   /*******************
    * Check Feasibility *
    *******************/
   SCIP_Bool feasible;
   SCIPinfoMessage(scip, NULL, "check the feasibility of <%s> for problem <%s> ...\n\n", argv[2], argv[1]);
   SCIP_CALL( SCIPcheckSolOrig(scip,sol,&feasible,TRUE,TRUE) );
   if (feasible == TRUE)
   {
        SCIPinfoMessage(scip, NULL, "The solution <%s> is optimal to <%s> \n\n", argv[2], argv[1]);
   }else
   {
        SCIPinfoMessage(scip, NULL, "The solution <%s> is not feasible to <%s> \n\n", argv[2], argv[1]);
        SCIPinfoMessage(scip, NULL, "Now, try to reoptimize the problem <%s> ...  \n\n",argv[1]);
   }
   
   /**************
    * Create alpha *
    **************/
   SCIP_Real obj0 = 0;
   SCIP_Real alpha = 0;
   int k = atoi(argv[3]);
   printf("the value k is %d\n", k);
   obj0 = SCIPsolGetOrigObj(sol);
   SCIPinfoMessage(scip, NULL, "The objective value of solution <%s>  is %f \n\n",argv[2],obj0);
   /* is there multiplication in scip?  */
   alpha = obj0 * k; 
   SCIPinfoMessage(scip, NULL, "The value of alpha is %f \n\n",alpha);
   

   /************************************
    * Create variables and constraints *
    ************************************/
   SCIP_VAR** x;
   SCIP_VAR** y;
   int n = SCIPgetNVars(scip);  //get the number of variables
   int i;
   int j = 0;
   

   x = SCIPgetVars(scip);       // get the variables

    for (i=0;i<n;i++)
    {
         SCIP_CALL( SCIPprintVar(scip,x[i],NULL));         // print the variables x
    }

     /* allocate array to store variables and coefficients */
     SCIP_CALL( SCIPallocBufferArray(scip, &y, n) );

     SCIPinfoMessage(scip, NULL, "Start to test variable y\n");

     for( i = 0; i < n; ++i )
     {   
        if(SCIPvarGetType(x[i]) == SCIP_VARTYPE_INTEGER  || SCIPvarGetType(x[i]) == SCIP_VARTYPE_BINARY )  // if the var type is integer or binary
        { 
          /* create variable y_j and add it into problem p2 */
          char yname[SCIP_MAXSTRLEN];
          (void) SCIPsnprintf(yname, SCIP_MAXSTRLEN, "y_%d", j);
          SCIP_CALL( SCIPcreateVarBasic(scip, &y[j], yname, 0.0, SCIPinfinity(scip), 1.0, SCIP_VARTYPE_INTEGER) );
          SCIP_CALL( SCIPaddVar(scip, y[j]) );
          SCIP_CALL( SCIPprintVar(scip,y[j],NULL));    
          j++;

          /*  add one constraint to problem p^2 */
          SCIP_VAR** vars;
          SCIP_CONS* cons;
          SCIP_Real* coefs;
          char ConName[SCIP_MAXSTRLEN];
          (void) SCIPsnprintf(ConName, SCIP_MAXSTRLEN, "y_%d_1", j);

          vars[1] = y[j];
          vars[2] = x[i];
          SCIP_CALL( SCIPallocBufferArray(scip, &coefs, 2) );
          coefs[0] = -1.0;
          coefs[1] = 1.0;

          // SCIP_Real v0 = SCIPgetSolVal(scip,sol,x[i]);  // get the value of variable xi in solution s0
          /* The variable name in scip and sol are not same. see ./build/output 
             I think this maybe because the sol file contains the transformed variable name */


          //  SCIP_CALL( SCIPcreateConsBasicLinear(
          //      scip,                    /* SCIP data structure */
          //      &cons,                   /* pointer to hold the created constraint */
          //      ConName,                 /* name of constraint */
          //      2,                       /* number of nonzeros in the constraint */
          //      vars,                    /* array with variables of constraint entries */
          //      coefs,                   /* array with variables of constraint entries */
          //      -SCIPinfinity(scip),     /* left hand side of constraint */
          //      v0                       /* right hand side of constraint */
          //      ) );  // create a linear constraint

          // /* change the coefficient and add another constraint */
          // coefs[0] = -1.0;
          // coefs[1] = -1.0;
          //  SCIP_CALL( SCIPcreateConsBasicLinear(
          //      scip,                    /* SCIP data structure */
          //      &cons,                   /* pointer to hold the created constraint */
          //      ConName,                 /* name of constraint */
          //      2,                       /* number of nonzeros in the constraint */
          //      vars,                    /* array with variables of constraint entries */
          //      coefs,                   /* array with variables of constraint entries */
          //      -SCIPinfinity(scip),     /* left hand side of constraint */
          //      -v0                       /* right hand side of constraint */
          //      ) );  // create a linear constraint


// SCIPgetSolVal   // get the variable value in the solution
//          
//           SCIP_CALL( SCIPaddCons(scip, cons) );
//           SCIP_CALL( SCIPreleaseCons(scip, &cons) );
        }
   }
   SCIPinfoMessage(scip, NULL, "This is the end of test variable y\n");




   /************************************
    * change the objective value *
    ************************************/
//    SCIPinfoMessage(scip, NULL, "This is the beginning of the reoptimization process \n");
     int r = 1;
     while(alpha > 0 ){
          alpha = alpha - alpha / k;
          for (i = 0; i <j; i++)
          {
               SCIP_CALL( SCIPchgVarObj(scip,y[i],alpha) );
          }
          SCIPinfoMessage(scip, NULL, "This is the %d-th iteration ...\n\n",r);
          // need to reoptimize the problem
          //  SCIP_CALL( SCIPsolve(scip) );
     }
     




   /************************************
    * change the objective value *
    ************************************/
   // SCIPchgVarObj()




   /*******************
    * Solve the Problem *
    *******************/
   // SCIPinfoMessage(scip, NULL, "solve problem ...\n\n");
   // SCIP_CALL( SCIPsolve(scip) );
   // SCIPinfoMessage(scip, NULL, "primal solution:\n");
   // SCIP_CALL( SCIPprintBestSol(scip, NULL, FALSE) );


   /**************
    * Statistics *
    **************/
   // SCIPinfoMessage(scip, NULL, "Statistics:\n");
   // SCIP_CALL( SCIPprintStatistics(scip, NULL) );


   /********************
    * Deinitialization *
    ********************/
   /* free SCIP */
   //            /* release variables */
//           SCIP_CALL( SCIPreleaseVar(scip, &y) );
   for( i = j - 1; i >= 0; --i )
   {
      SCIP_CALL( SCIPreleaseVar(scip, &y[i]) );
   }
   SCIP_CALL( SCIPfreeSol(scip,&sol) );
   SCIP_CALL( SCIPfree(&scip) );
   
   /* check block memory */
   BMScheckEmptyMemory();


   // if( retcode != SCIP_OKAY )
   // {
   //    SCIPprintError(retcode);
   //    return -1;
   // }

   return 0;

}
