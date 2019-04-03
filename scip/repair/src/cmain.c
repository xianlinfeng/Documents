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
int main(
    int argc,   /**< number of arguments from the shell */
    char **argv /**< array of shell arguments */
)
{
   SCIP *scip = NULL;
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
   SCIP_CALL(SCIPcreate(&scip));

   /***********************
    * Version information *
    ***********************/
   SCIPprintVersion(scip, NULL);
   SCIPinfoMessage(scip, NULL, "\n");

   /* include default SCIP plugins */
   SCIP_CALL(SCIPincludeDefaultPlugins(scip));

   /********************
    * Problem Creation *
    ********************/
   SCIPinfoMessage(scip, NULL, "read problem <%s> ...\n\n", argv[1]);
   SCIP_CALL(SCIPreadProb(scip, argv[1], NULL));
   //    SCIP_CALL( SCIPprintOrigProblem(scip,NULL,NULL,TRUE) );   // print the problem

   /********************
    * Read Solution *
    ********************/
   SCIP_SOL *sol = NULL;
   SCIP_Bool partial = TRUE;
   SCIP_Bool error = FALSE;
   SCIPinfoMessage(scip, NULL, "read solution <%s> ...\n\n", argv[2]);
   SCIP_CALL(SCIPcreateSol(scip, &sol, NULL));
   SCIP_CALL(SCIPreadSolFile(scip, argv[2], sol, FALSE, &partial, &error));
   /* print the solution */
   // SCIPinfoMessage(scip, NULL, "print the original solution from file <%d> ...\n\n", argv[2]);
   // SCIP_CALL(SCIPprintSol(scip, sol, NULL, TRUE)); // print the solution

   /*******************
    * Check Feasibility *
    *******************/
   SCIP_Bool feasible;
   SCIPinfoMessage(scip, NULL, "check the feasibility of <%s> for problem <%s> ...\n\n", argv[2], argv[1]);
   SCIP_CALL(SCIPcheckSolOrig(scip, sol, &feasible, TRUE, TRUE));
   if (feasible == TRUE)
   {
      SCIPinfoMessage(scip, NULL, "The solution <%s> is optimal to <%s> \n\n", argv[2], argv[1]);
      // return 0;   // stop
   }
   else
   {
      SCIPinfoMessage(scip, NULL, "The solution <%s> is not feasible to <%s> \n\n", argv[2], argv[1]);
      SCIPinfoMessage(scip, NULL, "Now, try to reoptimize the problem <%s> ...  \n\n", argv[1]);
   }

   /**************
    * Create alpha *
    **************/
   SCIP_Real obj0 = 0;
   SCIP_Real alpha = 0;
   int k = atoi(argv[3]);
   printf("the value k is %d\n", k);
   obj0 = SCIPsolGetOrigObj(sol);
   SCIPinfoMessage(scip, NULL, "The objective value of solution <%s>  is %f \n", argv[2], obj0);
   /* is there multiplication in scip?  */
   alpha = obj0 * k;
   SCIPinfoMessage(scip, NULL, "The value of alpha is %f \n\n", alpha);

   /************************************
    * Create variables and constraints *
    ************************************/
   SCIP_VAR **x;
   SCIP_VAR **y;
   int n = SCIPgetNVars(scip); //get the number of variables

   printf("No. of variables is %d\n\n", n);

   x = SCIPgetVars(scip); // get the variables

   // for (i = 0; i < n; i++)
   // {
   //    SCIP_CALL(SCIPprintVar(scip, x[i], NULL)); // print the variables x
   // }

   // SCIP_CALL(SCIPprintSol(scip, sol, NULL, FALSE));

   /* print the constraints */
   // SCIP_CONS **conss;
   // conss = SCIPgetConss(scip);
   // SCIP_CALL(SCIPprintCons(scip, *conss, NULL));

   /* allocate array to store variables*/
   SCIP_CALL(SCIPallocMemoryArray(scip, &y, n));

   SCIPinfoMessage(scip, NULL, "Start to add variable y and new constraints \n\n");
   int i;
   int j = 0;
   for (i = 0; i < n; i++)
   {
      if (SCIPvarGetType(x[i]) == SCIP_VARTYPE_INTEGER || SCIPvarGetType(x[i]) == SCIP_VARTYPE_BINARY) // if the var type is integer or binary
      {                                                                                                // SCIP_CALL(SCIPprintVar(scip, x[i], NULL));
         printf("i %d, status %d, %s\n", i, SCIPvarGetStatus(x[i]), SCIPvarGetName(x[i]));
         /* create variable y_j and add it into problem p2 */
         char yname[SCIP_MAXSTRLEN];
         (void)SCIPsnprintf(yname, SCIP_MAXSTRLEN, "y%d", j);
         SCIP_CALL(SCIPcreateVarBasic(scip, &y[j], yname, 0.0, SCIPinfinity(scip), alpha, SCIP_VARTYPE_CONTINUOUS)); // yj is continuous so scip won't branch on y
         SCIP_CALL(SCIPaddVar(scip, y[j]));
         // SCIP_CALL(SCIPprintVar(scip, y[j], NULL)); // print the variable y

         /*  add one constraint to problem p^2 */
         SCIP_CONS *cons;
         char ConName[SCIP_MAXSTRLEN];
         (void)SCIPsnprintf(ConName, SCIP_MAXSTRLEN, "y%d_1", j);

         SCIP_VAR *vars[] = {y[j], x[i]};
         SCIP_Real coefs_1[] = {-1.0, 1.0};

         SCIP_Real varValue = SCIPgetSolVal(scip, sol, x[i]); // get the value of variable xi in solution s0
         // SCIPinfoMessage(scip, NULL, "the variable %d value is %f \n", i, varValue);
         SCIP_CALL(SCIPcreateConsBasicLinear(
             scip,                /* SCIP data structure */
             &cons,               /* pointer to hold the created constraint */
             ConName,             /* name of constraint */
             2,                   /* number of nonzeros in the constraint */
             vars,                /* array with variables of constraint entries */
             coefs_1,             /* array with variables of constraint entries */
             -SCIPinfinity(scip), /* left hand side of constraint */
             varValue             /* right hand side of constraint */
             ));                  // create a linear constraint
         /* add constraint to SCIP */
         SCIP_CALL(SCIPaddCons(scip, cons));
         SCIPinfoMessage(scip, NULL, "The first constraint is added!!  \n");

         // /* change the coefficient and add another constraint */
         (void)SCIPsnprintf(ConName, SCIP_MAXSTRLEN, "y%d_2", j);
         SCIP_Real coefs_2[] = {-1.0, -1.0};
         SCIP_CALL(SCIPcreateConsBasicLinear(
             scip,                /* SCIP data structure */
             &cons,               /* pointer to hold the created constraint */
             ConName,             /* name of constraint */
             2,                   /* number of nonzeros in the constraint */
             vars,                /* array with variables of constraint entries */
             coefs_2,             /* array with variables of constraint entries */
             -SCIPinfinity(scip), /* left hand side of constraint */
             -varValue            /* right hand side of constraint */
             ));                  // create a linear constraint
         /* add constraint to SCIP */
         SCIP_CALL(SCIPaddCons(scip, cons));
         SCIPinfoMessage(scip, NULL, "The seconde= constraint is added!!  \n\n");

         /* release constraint (if not needed anymore) */
         SCIP_CALL(SCIPreleaseVar(scip, &vars[0]));
         SCIP_CALL(SCIPreleaseVar(scip, &vars[1]));
         SCIP_CALL(SCIPreleaseCons(scip, &cons));
         j++;
      }
   }

   /* after add y and constraints into the problem */
   /*******************
    * print variables *
    *******************/
   // n = SCIPgetNVars(scip);
   // x = SCIPgetVars(scip);
   // SCIPinfoMessage(scip, NULL, "New, No. of variables is %d\n\n ", n);
   // for (i = 0; i < n; i++)
   // {
   //    SCIP_CALL(SCIPprintVar(scip, x[i], NULL));
   // }

   /************************
    * print the constraints *
    *************************/
   // SCIP_CONS **m = SCIPgetOrigConss(scip);
   // i = 0;
   // while (m[i] != NULL)
   // {
   //    SCIP_CALL(SCIPprintCons(scip, m[i], NULL));
   //    SCIPinfoMessage(scip, NULL, "\n ");
   //    i++;
   // }

   /************************
    * print the problem *
    *************************/
   SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, FALSE));

   /*************************************************
    * write the problem to a file  *
    *************************************************/
   // SCIP_CALL(SCIPwriteOrigProblem(scip, "newbell5.lp", "lp", FALSE));

   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, FALSE));  // print the problem

   //    SCIPinfoMessage(scip, NULL, "This is the end of test variable y\n");

   //    /************************************
   //     * reoptimize the problem  *
   //     ************************************/
   //   SCIPinfoMessage(scip, NULL, "This is the beginning of the reoptimization process \n");
   //   /* enable reoptimization */
   //   SCIP_CALL(  SCIPenableReoptimization(scip,TRUE) );

   /* thresholds to trigger a restart from scratch */
   //   SCIP_CALL( SCIPsetIntParam(scip, "reoptimization/advanced/maxsavednodes", 2147483647) );
   //   SCIP_CALL( SCIPsetIntParam(scip, "reoptimization/advanced/delay",-1));
   //   SCIP_CALL( SCIPsetIntParam(scip, "reoptimization/advanced/forceheurrestart",5));

   /* stop criterion for solving process */
   //   SCIP_CALL( SCIPsetIntParam(scip, "limits/node", 99999) );
   //   SCIP_CALL( SCIPsetIntParam(scip, "limits/stallnodes", 2000) );
   //   SCIP_CALL( SCIPsetIntParam(scip, "limits/time", 120) );

   //      int r = 1;
   //   while(alpha > 0 ){
   //        alpha = alpha - alpha / k;
   //        for (i = 0; i <j ; i++)
   //        {
   //             SCIP_CALL( SCIPchgVarObj(scip,y[i],alpha) );   // should I read the variables from problem again?
   //        }
   //        SCIPinfoMessage(scip, NULL, "This is the %d-th iteration ...\n\n",r);

   /* change objective */
   // SCIPchgVarObj()
   //  for( i=0;i<j;i++)
   //  {
   //       SCIP_CALL( SCIPchgVarObj(scip,y[i],alpha) );
   //  }
   //   SCIP_CALL( SCIPsolve(scip) );
   // }

   /**********************
    * Solve the problem  *
    **********************/
   /* change the stop criterion */
   SCIP_CALL(SCIPsetRealParam(scip, "limits/gap", 0.1));
   /* solve the IP */
   SCIP_CALL(SCIPsolve(scip));

   /* print best solution */
   // SCIP_CALL(SCIPprintBestSol(scip, NULL, TRUE));

   /******************
    * check solution *
    ******************/
   // set/checksol    to double check the solution to the original problem

   /********************
    * Deinitialization *
    ********************/
   /* release variables */
   for (i = 0; i < j; i++)
   {
      // SCIP_CALL(SCIPprintVar(scip, y[i], NULL));
      SCIP_CALL(SCIPreleaseVar(scip, &y[i]));
   }

   /* free sol and SCIP */
   SCIP_CALL(SCIPfreeSol(scip, &sol));
   SCIP_CALL(SCIPfree(&scip));

   /* check block memory */
   BMScheckEmptyMemory();

   // if( retcode != SCIP_OKAY )
   // {
   //    SCIPprintError(retcode);
   //    return -1;
   // }

   return 0;
}
