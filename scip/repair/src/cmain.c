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

   /* we explicitly enable the use of a debug solution for this main SCIP instance */
   SCIPenableDebugSol(scip);

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
   printf("the value h is %d\n", k);
   obj0 = SCIPsolGetOrigObj(sol);
   SCIPinfoMessage(scip, NULL, "The objective value of solution <%s>  is %f \n\n",argv[2],obj0);
   alpha = obj0 * k;
   SCIPinfoMessage(scip, NULL, "The value of alpha is %f \n\n",alpha);
   

   /************************************
    * Create variables and constraints *
    ************************************/
   SCIP_VAR* x;
   int n = SCIPgetNVars(scip);  //get the number of variables
   int i;

   for (i = 0;i<n;++i)
   {
        SCIP_CALL( SCIPcreateVarBasic(scip,&x,NULL,-SCIPinfinity(scip),SCIPinfinity(scip),0.0,SCIP_VARTYPE_CONTINUOUS) );
     //    x++;
   }

//    x = SCIPgetVars(scip);
   SCIP_CALL(SCIPprintVar(scip,x,NULL));
  
//    for(i = 0; i < n; i++)
//    {    
//         if(SCIPvarGetType(x[i]) == SCIP_VARTYPE_INTEGER)  // if the var type is integer
//         { 
//           SCIP_VAR* y;
//           SCIP_CONS* cons;
//           char name[SCIP_MAXSTRLEN];

//           SCIP_CALL( SCIPcreateVarBasic(scip, &y, "y", -SCIPinfinity(scip), SCIPinfinity(scip), 1.0, SCIP_VARTYPE_INTEGER) );
//           SCIP_CALL( SCIPaddVar(scip, y) );

//           SCIP_CALL( SCIPcreateVarBasic(scip, &y, "y", -SCIPinfinity(scip), SCIPinfinity(scip), 1.0, SCIP_VARTYPE_INTEGER) );
//           SCIP_CALL( SCIPaddVar(scip, y) );
     
//           snprintf(name,SCIP_MAXSTRLEN, "y%d", i);  // assignment the name to the constraint
//           SCIP_CALL( SCIPcreateConsBasicSOC(scip, &cons, name, 2, ab, NULL, xy, 0.0, r, 1.0, 0.0) );
//           SCIP_CALL( SCIPcreateConsBasicLinear(scip, &cons, name, 2, ab, NULL, xy, 0.0, r, 1.0, 0.0) );  // create a linear constraint
//           SCIP_CALL( SCIPaddCons(scip, cons) );
//           SCIP_CALL( SCIPreleaseCons(scip, &cons) );

//            /* release variables */
//           SCIP_CALL( SCIPreleaseVar(scip, &y) );

//         }
//    }

     // SCIPaddObjoffset(); add the penalty function to objective


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
