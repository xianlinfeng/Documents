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
   if (argc != 5)
   {
      printf("There must exist 4 arguments:  p^1,  s^0,  p, k. \n");
      printf("File p^1:    the problem with added constraints.\n");
      printf("File s^0:    the solution to the original problem.\n");
      printf("Integer u:   alpha = u * obj_s0 \n");
      printf("Iteger k:    the number of iterations\n\n");
      return 1;
   }
   int u = atoi(argv[3]);
   int k = atoi(argv[4]);
   assert(u > 0);
   assert(k > 0);

   SCIP *scip = NULL;
   SCIP_RETCODE retcode;

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
   SCIP_CALL(SCIPresetParams(scip));
   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, FALSE));

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
      return 0; // stop when s^0 is feasible to p^1
   }
   else
   {
      SCIPinfoMessage(scip, NULL, "The solution <%s> is not feasible to <%s> \n\n", argv[2], argv[1]);
      SCIPinfoMessage(scip, NULL, "Tring to reoptimize the problem <%s> ...  \n\n", argv[1]);
   }

   /**************
    * Create alpha *
    **************/
   SCIP_Real alpha = SCIPsolGetOrigObj(sol) * u;
   SCIPinfoMessage(scip, NULL, "obj = %f, k = %d, alpha = %f \n\n", SCIPsolGetOrigObj(sol), k, alpha);

   /************************************
    * Create variables and constraints *
    ************************************/
   SCIP_VAR **x;
   x = SCIPgetVars(scip);      // get the variables
   int n = SCIPgetNVars(scip); //get the number of variables
   SCIPinfoMessage(scip, NULL, "n = %d \n\n", n);

   /* allocate array to store variables*/
   SCIP_VAR **y;
   SCIP_CALL(SCIPallocMemoryArray(scip, &y, n));
   int j = 0;

   SCIPinfoMessage(scip, NULL, "Start to add variable y and new constraints \n\n");

   for (int i = 0; i < n; i++)
   {
      // SCIP_CALL(SCIPprintVar(scip, x[i], NULL));
      // SCIPinfoMessage(scip, NULL, "\n\n No error since here!\n");
      if (SCIPvarGetType(x[i]) == SCIP_VARTYPE_INTEGER || SCIPvarGetType(x[i]) == SCIP_VARTYPE_BINARY) // if the var type is integer or binary
      {
         /* create variable y_j and add it into problem p2 */
         char yname[SCIP_MAXSTRLEN];
         (void)SCIPsnprintf(yname, SCIP_MAXSTRLEN, "y%d", j);
         SCIP_CALL(SCIPcreateVarBasic(scip, &y[j], yname, 0.0, SCIPinfinity(scip), alpha, SCIP_VARTYPE_CONTINUOUS));
         // SCIP_CALL(SCIPaddVar(scip, y[j]));
         SCIP_CALL(SCIPprintVar(scip, y[j], NULL)); // print the variable y

         SCIP_Real varValue = SCIPgetSolVal(scip, sol, x[i]); // get the value of variable xi in solution s0
         SCIPinfoMessage(scip, NULL, "value of var in sol is %f  \n", varValue);

         SCIP_VAR *vars[] = {y[j], x[i]};
         /*  add one constraint to problem p^2 */
         char ConName[SCIP_MAXSTRLEN];
         (void)SCIPsnprintf(ConName, SCIP_MAXSTRLEN, "y%d_1", j);
         SCIP_CONS *cons_1;

         SCIP_Real coefs_1[] = {-1.0, 1.0};
         SCIP_CALL(SCIPcreateConsBasicLinear(
             scip,                /* SCIP data structure */
             &cons_1,             /* pointer to hold the created constraint */
             ConName,             /* name of constraint */
             2,                   /* number of nonzeros in the constraint */
             vars,                /* array with variables of constraint entries */
             coefs_1,             /* array with variables of constraint entries */
             -SCIPinfinity(scip), /* left hand side of constraint */
             varValue             /* right hand side of constraint */
             ));                  // create a linear constraint
         SCIP_CALL(SCIPaddCons(scip, cons_1));
         // SCIP_CALL(SCIPprintCons(scip, cons_1, NULL));
         SCIP_CALL(SCIPreleaseCons(scip, &cons_1));
         // // SCIPinfoMessage(scip, NULL, "The first constraint is added!!  \n");
         SCIPinfoMessage(scip, NULL, "\n");

         /* change the coefficient and add another constraint */
         (void)SCIPsnprintf(ConName, SCIP_MAXSTRLEN, "y%d_2", j);
         SCIP_CONS *cons_2;
         SCIP_Real coefs_2[] = {-1.0, -1.0};
         SCIP_CALL(SCIPcreateConsBasicLinear(
             scip,                /* SCIP data structure */
             &cons_2,             /* pointer to hold the created constraint */
             ConName,             /* name of constraint */
             2,                   /* number of nonzeros in the constraint */
             vars,                /* array with variables of constraint entries */
             coefs_2,             /* array with variables of constraint entries */
             -SCIPinfinity(scip), /* left hand side of constraint */
             -varValue            /* right hand side of constraint */
             ));                  // create a linear constraint
         SCIP_CALL(SCIPaddCons(scip, cons_2));
         // SCIP_CALL(SCIPprintCons(scip, cons_2, NULL));
         SCIP_CALL(SCIPreleaseCons(scip, &cons_2));
         // SCIPinfoMessage(scip, NULL, "The seconde= constraint is added!!  \n\n");

         /* release constraint (if not needed anymore) */
         SCIP_CALL(SCIPreleaseVar(scip, &vars[0]));
         SCIP_CALL(SCIPreleaseVar(scip, &vars[1]));
         j++;
      }
   }
   /* free the solution */
   SCIP_CALL(SCIPfreeSol(scip, &sol));

   /* add and release the variables y */
   for (int i = j - 1; i >= 0; --i)
   {
      SCIP_CALL(SCIPaddVar(scip, y[i]));
      SCIP_CALL(SCIPreleaseVar(scip, &y[i]));
   }
   SCIPinfoMessage(scip, NULL, "y have been released ! \n\n");
   SCIPinfoMessage(scip, NULL, "Finish to create the y and constraint ! \n\n");
   SCIPinfoMessage(scip, NULL, "n = %d,  j = %d ! \n\n", n, j);

   /*******************
    * print variables *
    *******************/
   // n = SCIPgetNVars(scip);
   // SCIPinfoMessage(scip, NULL, "New, No. of variables is %d\n\n ", n);
   // x = SCIPgetVars(scip);

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
   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, FALSE));
   // SCIP_CALL(SCIPprintTransProblem(scip, NULL, NULL, TRUE));

   /*************************************************
    * write the problem to a file  *
    *************************************************/
   // SCIP_CALL(SCIPwriteOrigProblem(scip, "newbell5.lp", "lp", FALSE));

   /************************************
   * Set up reoptimize parameters *
   ************************************/
   SCIPinfoMessage(scip, NULL, "set all parameters to default! \n\n");
   SCIP_CALL(SCIPresetParams(scip));

   /* enable reoptimization */
   SCIP_CALL(SCIPenableReoptimization(scip, TRUE));
   SCIPinfoMessage(scip, NULL, "Reoptimization is enabled! \n\n");

   /* thresholds to trigger a restart from scratch */
   // SCIP_CALL(SCIPsetIntParam(scip, "reoptimization/maxsavednodes", 2147483647));
   // SCIP_CALL(SCIPsetRealParam(scip, "reoptimization/delay", -1));
   // SCIP_CALL(SCIPsetIntParam(scip, "reoptimization/forceheurrestart", 3));
   SCIPinfoMessage(scip, NULL, "Reoptimization parameter have been setted ! \n\n");

   /* stop criterion for solving process */
   SCIP_CALL(SCIPsetIntParam(scip, "misc/usesymmetry", 0));
   SCIP_CALL(SCIPsetRealParam(scip, "limits/gap", 0.0));
   SCIPinfoMessage(scip, NULL, "Stop parameter have been setted ! \n\n");

   /* get objective sense and coefficients */
   SCIP_OBJSENSE sense = SCIPgetObjsense(scip);
   n = SCIPgetNVars(scip); //get the number of variables
   x = SCIPgetVars(scip);  // get the variables
   SCIP_Real *coefs;
   SCIP_CALL(SCIPallocMemoryArray(scip, &coefs, n));
   SCIPinfoMessage(scip, NULL, "Memory for coefs have allocated ! \n\n");

   for (int i = 0; i < n; i++)
   {
      coefs[i] = SCIPvarGetObj(x[i]);
   }
   SCIPinfoMessage(scip, NULL, "Coefficients have been captured ! \n\n");

   /************************************
   * Reoptimization iteration begins   *
   ************************************/
   int r = 1;
   int m = k;
   while (m > 0)
   {
      SCIPinfoMessage(scip, NULL, "alpha = %f, n = %d, j = %d, m = %d \n", alpha, n, j, m);
      SCIPinfoMessage(scip, NULL, "This is the %d-th iteration ! \n\n", r);
      /* solve the problem first */
      SCIP_CALL(SCIPsolve(scip));
      SCIP_CALL(SCIPfreeReoptSolve(scip));
      m--;
      alpha = alpha * m / k;
      for (int i = n - j; i < n; i++)
      {
         coefs[i] = alpha;
      }
      SCIPinfoMessage(scip, NULL, "Coefs have been resetted!! \n\n");
      SCIP_CALL(SCIPchgReoptObjective(scip, sense, x, coefs, n));
      SCIPinfoMessage(scip, NULL, "Problem have been changed !! \n\n");
      // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, TRUE));
      r++;
   }

   /**************************************************
   * restore the limits and solve the last iteration *
   ***************************************************/
   SCIPinfoMessage(scip, NULL, "This is the last iteration \n\n\n");
   SCIPinfoMessage(scip, NULL, "alpha = %f  \n", alpha);
   SCIP_CALL(SCIPsetRealParam(scip, "limits/gap", 0.0));

   /* solve the IP */
   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, TRUE)); // print the last problem
   // SCIP_CALL(SCIPprintTransProblem(scip, NULL, NULL, TRUE));
   SCIP_CALL(SCIPsolve(scip));

   // /* print best solution */
   // SCIP_CALL(SCIPprintBestSol(scip, NULL, TRUE));

   /********************
    * Deinitialization *
    ********************/
   /* free the coefs */
   SCIPfreeMemoryArray(scip, &coefs);

   /* free sol and SCIP */
   // SCIPinfoMessage(scip, NULL, "No error here ! \n");
   SCIP_CALL(SCIPfree(&scip));

   /* check block memory */
   BMScheckEmptyMemory();

   return 0;
}
