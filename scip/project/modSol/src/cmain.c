/**@file   modSol/src/main.c
 * @brief  modify a solution for a MIP problem
 * @author Arthur Feng
 */

/* Introduction
   1. This program will read a MIP problem and a solution, then modify the binary variables of the solution base on a percentage,
      the program will make the solution more optimal(infeasible). 
   2. This program will read 3 prarmeters
      argv[0]: the command;
      argv[1]: the name of the problem, eg: neos-1122047
      argv[2]: the integer number of percentage of binary variables to modify.
      command: ./modSol neos-1122047 10
   3. it will read the problem from the directory: instances/
      it will read the solution form the directory: solution/
   4. it will put the modified solution in the directory 10solution/,
         which means 10% binary variables were modified
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "scip/scip.h"
#include "scip/scipdefplugins.h"
#include "scip/scip_reader.h"

/** main method */
int main(
    int argc,   /**< number of arguments from the shell */
    char **argv /**< array of shell arguments */
)
{
   if (argc != 3)
   {
      printf("There should be exactly 3 arguments \n");
      return 1;
   }

   SCIP *scip = NULL;
   SCIP_RETCODE retcode;
   char name[40];
   strcpy(name, argv[1]);

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
   char pro[] = "instances/";
   strcat(pro, name);
   strcat(pro, ".mps");
   SCIP_CALL(SCIPreadProb(scip, pro, NULL));
   SCIP_CALL(SCIPresetParams(scip));
   // SCIP_CALL(SCIPprintOrigProblem(scip, NULL, NULL, FALSE));
   strcpy(name, argv[1]);

   /********************
    * Read Solution *
    ********************/
   SCIP_SOL *sol = NULL;
   SCIP_Bool partial = TRUE;
   SCIP_Bool error = FALSE;
   // SCIPinfoMessage(scip, NULL, "read solution <%s> ...\n\n", argv[2]);
   SCIP_CALL(SCIPcreateSol(scip, &sol, NULL));
   char solName[] = "solution/";
   strcat(solName, name);
   strcat(solName, ".sol");
   SCIP_CALL(SCIPreadSolFile(scip, solName, sol, FALSE, &partial, &error));
   /* print the solution */
   // SCIPinfoMessage(scip, NULL, "print the original solution from file <%d> ...\n\n", argv[2]);
   // SCIP_CALL(SCIPprintSol(scip, sol, NULL, FALSE)); // print the solution
   strcpy(name, argv[1]);

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
   int r = atoi(argv[2]);
   char sr[4];
   // itoa(r, sr, 10);
   // printf("sr = %s \n", sr);
   sprintf(sr, "%d", r);
   printf("sr = %s \n", sr);

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

   char dic[] = "/home/arthur/Documents/scip/project/";
   strcat(dic, sr);
   strcat(dic, "solution/");
   // printf("dic = %s \n ", dic);

   strcat(dic, name);
   strcat(dic, "_1.sol");
   SCIPinfoMessage(scip, NULL, "dic = %s \n\n", dic);
   FILE *file;
   file = fopen(dic, "w+");
   SCIP_CALL(SCIPprintSol(scip, sol, file, FALSE));
   fclose(file);
   // SCIPinfoMessage(scip, NULL, "No error here \n\n");

   /* free the solution */
   SCIP_CALL(SCIPfreeSol(scip, &sol));

   /* free sol and SCIP */
   // SCIPinfoMessage(scip, NULL, "No error here ! \n");
   SCIP_CALL(SCIPfree(&scip));

   /* check block memory */
   BMScheckEmptyMemory();

   return 0;
}
