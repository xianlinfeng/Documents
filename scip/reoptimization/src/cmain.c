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
    int argc,    /**< number of arguments from the shell */
    char *argv[] /**< array of shell arguments */
)
{
   SCIP *scip = NULL;
   SCIP_RETCODE retcode;

   if (argc != 3)
   {
      printf("There must exist 2 arguments:\" new problem p\", and a integer number k \n\n");
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
   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, TRUE)); // print the problem

   /* get the variables of the problem */
   SCIP_VAR **vars = SCIPgetVars(scip);
   int n = SCIPgetNVars(scip);
   // for (int i = 0; i < n; i++)
   // {
   //    SCIP_CALL(SCIPprintVar(scip, vars[i], NULL));
   // }

   /**************
    * Create alpha *
    **************/
   int alpha = atoi(argv[2]);
   SCIPinfoMessage(scip, NULL, "The value of alpha is %d \n\n", alpha);

   /************************************
   * reoptimize the problem  *
   ************************************/
   SCIPinfoMessage(scip, NULL, "set all parameters to default! \n\n");
   SCIP_CALL(SCIPresetParam(scip, "default"));

   /* enable reoptimization */
   SCIP_CALL(SCIPenableReoptimization(scip, TRUE));
   SCIPinfoMessage(scip, NULL, "Reoptimization is enabled! \n\n");

   /* thresholds to trigger a restart from scratch */
   SCIP_CALL(SCIPsetIntParam(scip, "reoptimization/maxsavednodes", 2147483647));
   SCIP_CALL(SCIPsetRealParam(scip, "reoptimization/delay", -1));
   SCIP_CALL(SCIPsetIntParam(scip, "reoptimization/forceheurrestart", 3));
   SCIPinfoMessage(scip, NULL, "Reoptimization parameter have been setted ! \n\n");

   /* stop criterion for solving process */
   // SCIP_CALL(SCIPsetLongintParam(scip, "limits/nodes", 500));
   // solving stops, if the given number of nodes was processed since the last improvement of the primal solution value
   // SCIP_CALL(SCIPsetLongintParam(scip, "limits/stallnodes", 300));
   // SCIP_CALL(SCIPsetRealParam(scip, "limits/time", 10.0));
   SCIP_CALL(SCIPsetRealParam(scip, "limits/gap", 0.7));
   SCIPinfoMessage(scip, NULL, "Stop parameter have been setted ! \n\n");

   /* get objective sense */
   SCIP_OBJSENSE sense = SCIPgetObjsense(scip);
   SCIP_Real *coefs;
   SCIP_CALL(SCIPallocMemoryArray(scip, &coefs, n));
   for (int i = 0; i < n; i++)
   {
      coefs[i] = SCIPvarGetObj(vars[i]);
   }

   int r = 1;
   do
   {
      SCIPinfoMessage(scip, NULL, "This is the %d-th iteration ! \n\n", r);
      /* solve the problem first */
      SCIP_CALL(SCIPsolve(scip));
      SCIP_CALL(SCIPfreeReoptSolve(scip));
      for (int i = 900; i < n; i++)
      {
         coefs[i] = alpha * 500;
      }
      SCIPinfoMessage(scip, NULL, "Coefs have been resetted!! \n\n");
      SCIP_CALL(SCIPchgReoptObjective(scip, sense, vars, coefs, n));
      SCIPinfoMessage(scip, NULL, "Problem have been changed !! \n\n");
      // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, TRUE));
      alpha--;
      r++;
   } while (alpha >= 0);

   /**************************************************
   * restore the limits and solve the last iteration *
   ***************************************************/
   SCIPinfoMessage(scip, NULL, "This is the last iteration \n\n\n");
   // SCIP_CALL(SCIPsetLongintParam(scip, "limits/nodes", -1));
   // SCIP_CALL(SCIPsetLongintParam(scip, "limits/stallnodes", -1));
   // SCIP_CALL(SCIPsetRealParam(scip, "limits/time", 10000));
   SCIP_CALL(SCIPsetRealParam(scip, "limits/gap", 0.0));
   /* solve the IP */
   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, TRUE)); // print the last problem
   SCIP_CALL(SCIPsolve(scip));

   /* print best solution */
   SCIP_CALL(SCIPprintBestSol(scip, NULL, TRUE));

   /**************
    * Statistics *
    **************/
   // SCIPinfoMessage(scip, NULL, "Statistics:\n");
   // SCIP_CALL( SCIPprintStatistics(scip, NULL) );

   // set/checksol    to double check the solution to the original problem

   /********************
    * Deinitialization *
    ********************/
   /* free SCIP */
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
