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
   if (argc != 4)
   {
      printf("There should be exactly 3 arguments \n");
      return 1;
   }

   SCIP *scip = NULL;
   SCIP_RETCODE retcode;

   /*********
    * Setup *
    *********/
   /* initialize SCIP */
   SCIP_CALL(SCIPcreate(&scip));

   /* include default SCIP plugins */
   SCIP_CALL(SCIPincludeDefaultPlugins(scip));

   /********************
    * Problem Creation *
    ********************/
   // SCIPinfoMessage(scip, NULL, "read problem <%s> ...\n\n", argv[1]);
   SCIP_CALL(SCIPreadProb(scip, argv[1], NULL));
   SCIP_CALL(SCIPresetParams(scip));
   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, FALSE));

   /********************
    * Read Solution *
    ********************/
   SCIP_SOL *sol = NULL;
   SCIP_Bool partial = TRUE;
   SCIP_Bool error = FALSE;
   // SCIPinfoMessage(scip, NULL, "read solution <%s> ...\n\n", argv[2]);
   SCIP_CALL(SCIPcreateSol(scip, &sol, NULL));
   SCIP_CALL(SCIPreadSolFile(scip, argv[2], sol, FALSE, &partial, &error));
   /* print the solution */
   // SCIPinfoMessage(scip, NULL, "print the original solution from file <%d> ...\n\n", argv[2]);
   // SCIP_CALL(SCIPprintSol(scip, sol, NULL, FALSE)); // print the solution

   // SCIPinfoMessage(scip, NULL, "No error here \n\n");
   // return 0;

   char solution[40];
   char *name;
   strcpy(solution, argv[1]);
   const char s[2] = ".";
   name = strtok(solution, s);
   // printf("The name of the solution is %s \n", name);

   /* create random number generator */
   static const unsigned int randseed = 42;
   SCIP_RANDNUMGEN *randnumgen;
   SCIP_CALL(SCIPcreateRandom(scip, &randnumgen, randseed, TRUE));

   /************************************
    * Create variables and constraints *
    ************************************/
   SCIP_VAR **x;
   int n;
   SCIP_CALL(SCIPgetSolVarsData(scip, sol, &x, &n, NULL, NULL, NULL, NULL));
   int r = atoi(argv[3]);

   for (int i = 0; i < n; i++)
   {
      // SCIPinfoMessage(scip, NULL, "No error since here!! \n");
      SCIP_Real varValue = SCIPgetSolVal(scip, sol, x[i]);
      SCIP_Real varObj = SCIPvarGetObj(x[i]);

      if (SCIPvarGetType(x[i]) == SCIP_VARTYPE_BINARY)
      {
         SCIP_Real varValue = SCIPgetSolVal(scip, sol, x[i]);
         SCIP_Real rand = SCIPrandomGetReal(randnumgen, 1.0, 100.0);
         if (rand <= r)
         {
            // SCIPinfoMessage(scip, NULL, "rand = %f \n", rand);
            // SCIPinfoMessage(scip, NULL, "varValue = %f \n", varValue);
            // SCIPinfoMessage(scip, NULL, "varObj = %f \n", varObj);
            if (varObj > 0 && varValue == 1)
            {
               // SCIPinfoMessage(scip, NULL, "The obj > 0, and varValue == 1 \n\n");
               SCIP_CALL(SCIPsetSolVal(scip, sol, x[i], 0.0));
            }

            if (varObj < 0 && varValue == 0)
            {
               // SCIPinfoMessage(scip, NULL, "The obj < 0, and varValue == 0 \n\n");
               SCIP_CALL(SCIPsetSolVal(scip, sol, x[i], 1.0));
            }
         }
      }
   }

   /* free random number generator */
   SCIPfreeRandom(scip, &randnumgen);

   char dic[60] = "/home/arthur/Downloads/Archive/p0Solution/";
   strcat(name, "_1.sol");
   strcat(dic, name);

   FILE *file;
   file = fopen(dic, "w+");
   SCIP_CALL(SCIPprintSol(scip, sol, file, FALSE));
   fclose(file);

   /* free the solution */
   SCIP_CALL(SCIPfreeSol(scip, &sol));

   /* free sol and SCIP */
   // SCIPinfoMessage(scip, NULL, "No error here ! \n");
   SCIP_CALL(SCIPfree(&scip));

   /* check block memory */
   BMScheckEmptyMemory();

   return 0;
}
