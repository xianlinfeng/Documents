/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                  This file is part of the program and library             */
/*         SCIP --- Solving Constraint Integer Programs                      */
/*                                                                           */
/*    Copyright (C) 2002-2019 Konrad-Zuse-Zentrum                            */
/*                            fuer Informationstechnik Berlin                */
/*                                                                           */
/*  SCIP is distributed under the terms of the ZIB Academic License.         */
/*                                                                           */
/*  You should have received a copy of the ZIB Academic License              */
/*  along with SCIP; see the file COPYING. If not visit scip.zib.de.         */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**@file   CycleClustering/src/main.c
 * @brief  Main file for C compilation
 * @author Leon Eifler
 */

/*--+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0----+----1----+----2*/
#include <stdio.h>

#include "scip/scip.h"
#include "scip/scipdefplugins.h"
#include "scip/scip_reader.h"
#include <string.h>



/** starts SCIP */
static
SCIP_RETCODE checkSol(
   SCIP*                 scip,               /**< SCIP data structure */
   const char*           solution,           /**< input solution file name */
   const char*           problem             /**< input problem file name */
   )
{
   /********************
    * Problem Creation *
    ********************/
   SCIPinfoMessage(scip, NULL, "read problem <%s> ...\n\n", problem);
   SCIP_CALL( SCIPreadProb(scip, problem, NULL) );

   /********************
    * Read Solution *
    ********************/
   SCIPinfoMessage(scip, NULL, "read solution <%s> ...\n\n", solution);
   SCIP_CALL( SCIPreadSol(scip, solution) ); 

   /*******************
    * Check Feasibility *
    *******************/
   SCIPinfoMessage(scip, NULL, "check the feasibility of <%s> for problem <%s> ...\n\n", solution, problem);
   SCIP_CALL( SCIPcheckSol );  //checks solution for feasibility without adding it to the solution store

   return SCIP_OKAY;

   // this part of code is from "scip/examples/GMI"
}



/** reads parameters */
static
SCIP_RETCODE setParams(
   SCIP*                 scip,               /**< SCIP data structure */
   const char*           filename            /**< parameter file name, or NULL */
   )
{
   // this part of code is from "scip/examples/GMI"
}

/** creates a SCIP instance with default plugins, evaluates command line parameters, runs SCIP appropriately,
 *  and frees the SCIP instance
 */
static
SCIP_RETCODE runShell(
   int                   argc,               /**< number of shell parameters */
   char**                argv               /**< array with shell parameters */
   )
{
   SCIP_RETCODE retcode;
   
   SCIP* scip = NULL;

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


   /***********************
    * Check Solution *
    ***********************/
   SCIP_CALL(checkSol(scip,argv[3],argv[4]));
   if( retcode != SCIP_OKAY )
   {
        SCIPinfoMessage(scip, NULL, "the solution <%s> is optimal for <%s> \n\n",argv[3],argv[4]);
        return 0;
   }
   return SCIP_OKAY;
}


/** main method */
int
main(
        int argc,
        char**                argv
        )
{
        SCIP_RETCODE retcode;

        if (argc != 5)
        {
                printf("There must exist 4 arguments:\"setting file name\", \"solution s^0\", \" new problem p^1\", and \" iteration number k \" \n");
                return 1;
        } 

        retcode = runShell(argc, argv); 

        if( retcode != SCIP_OKAY )
        {
                SCIPprintError(retcode);
                return -1;
        }

        return 0;

}
