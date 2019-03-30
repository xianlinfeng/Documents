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

   if (argc != 3)
   {
      printf("There must exist 2 arguments:\"solution s^0\", \" new problem p^1\"\n");
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
   SCIP_Bool* 	partial = NULL;
   SCIP_Bool* 	error = NULL; 
   SCIPinfoMessage(scip, NULL, "read solution <%s> ...\n\n", argv[2]); 
   SCIP_CALL( SCIPreadSolFile(scip,argv[2],sol,FALSE,partial,error)); // this function don't work
   // when I use the function "SCIPreadSolFile" the out put always "Segmentation fault (core dumped)"

   // SCIP_CALL( SCIPreadSol(scip, argv[2]) );  // I can read the solution with this function, But I don't know how to check the feasibility.




   /*******************
    * Solve the Problem *
    *******************/
   // SCIPinfoMessage(scip, NULL, "solve problem ...\n\n");
   // SCIP_CALL( SCIPsolve(scip) );

   // SCIPinfoMessage(scip, NULL, "primal solution:\n");
   // SCIP_CALL( SCIPprintBestSol(scip, NULL, FALSE) );


   /*******************
    * Check Feasibility *
    *******************/
   SCIP_Bool * feasible;
   // SCIPinfoMessage(scip, NULL, "check the feasibility of <%s> for problem <%s> ...\n\n", argv[2], argv[1]);
   // SCIP_CALL( SCIPcheckSolOrig(scip,sol,feasible,TRUE,TRUE) );  //checks solution for feasibility without adding it to the solution store



   /**************
    * Statistics *
    **************/
   // SCIPinfoMessage(scip, NULL, "Statistics:\n");
   // SCIP_CALL( SCIPprintStatistics(scip, NULL) );


   /********************
    * Deinitialization *
    ********************/
   /* free SCIP */
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
