/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                  This file is part of the program and library             */
/*         SCIP --- Solving Constraint Integer Programs                      */
/*                                                                           */
/*    Copyright (C) 2002-2015 Konrad-Zuse-Zentrum                            */
/*                            fuer Informationstechnik Berlin                */
/*                                                                           */
/*  SCIP is distributed under the terms of the ZIB Academic License.         */
/*                                                                           */
/*  You should have received a copy of the ZIB Academic License              */
/*  along with SCIP; see the file COPYING. If not email to scip@zib.de.      */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**@file   cmain.c
 * @brief  Main file for the FirstIP example
 */
#include <stdio.h>
#include <assert.h>

/* access to the most important SCIP methods */
#include "FirstIP/src/scip/scip.h"

/* necessary to include default plugins */
#include "scip/scipdefplugins.h"

/** adds variables and constraints to SCIP */
static
SCIP_RETCODE createIP(SCIP* scip, int n, int k)
{
   SCIP_VAR** vars;
   SCIP_CONS* cons;
   SCIP_Real* coefs;
   char varname[SCIP_MAXSTRLEN];
   int i;

   assert(scip != NULL);

   /* create empty problem */
   SCIP_CALL( SCIPcreateProbBasic(scip, "coatwork-IP") );

   /* allocate array to store variables and coefficients */
   SCIP_CALL( SCIPallocBufferArray(scip, &vars, n) );
   SCIP_CALL( SCIPallocBufferArray(scip, &coefs, n) );

   for( i = 0; i < n; ++i )
   {
      /* store variable name in varname */
      (void) SCIPsnprintf(varname, SCIP_MAXSTRLEN, "x_%d", i);

      /* create variable */
      SCIP_CALL( SCIPcreateVarBasic(
            scip,                 /* SCIP data structure */
            &vars[i],             /* pointer to hold created variable */
            varname,              /* variable name */
            0.0,                  /* lower variable bound */
            1.0,                  /* upper variable bound */
            -REALABS(sin(i+1.0)), /* objective function value */
            SCIP_VARTYPE_BINARY   /* variable type */
            )
         );

      /* add variable to SCIP */
      SCIP_CALL( SCIPaddVar(scip, vars[i]) );

      /* set coefficient in coefs array */
      coefs[i] = i + 1.0;
   }

   /* create linear constraint */
   SCIP_CALL( SCIPcreateConsBasicLinear(
         scip,                  /* SCIP data structure */
         &cons,                 /* pointer to hold the created constraint */
         "cons1",               /* name of constraint */
         n,                     /* number of nonzeros in the constraint */
         vars,                  /* array with variables of constraint entries */
         coefs,                 /* array with variables of constraint entries */
         -SCIPinfinity(scip),   /* left hand side of constraint */
         (SCIP_Real) k          /* right hand side of constraint */
         ) );

   /* add constraint to SCIP */
   SCIP_CALL( SCIPaddCons(scip, cons) );

   /* release constraint (if not needed anymore) */
   SCIP_CALL( SCIPreleaseCons(scip, &cons) );

   /* release variables (if not needed anymore) */
   for( i = n - 1; i >= 0; --i )
   {
      SCIP_CALL( SCIPreleaseVar(scip, &vars[i]) );
   }

   /* free arrays */
   SCIPfreeBufferArray(scip, &coefs);
   SCIPfreeBufferArray(scip, &vars);

   return SCIP_OKAY;
}

/** creates and solves the following IP:
 *
 *        min sum_{i = 1,..,n} -|sin(i)| x_i
 *   s.t.     sum_{i = 1,..,n} i x_i <= k
 *                    x in {0,1}^n
 */
static
SCIP_RETCODE solveIP(int n, int k)
{
   SCIP* scip;

   assert(n > 0);
   assert(k > 0);

   /* creates and initializes SCIP data structure */
   SCIP_CALL( SCIPcreate(&scip) );

   /* include default plugins */
   SCIP_CALL( SCIPincludeDefaultPlugins(scip) );

   /* create the IP */
   SCIP_CALL( createIP(scip, n, k) );

   /* solve the IP */
   SCIP_CALL( SCIPsolve(scip) );

   /* print best solution */
   SCIP_CALL( SCIPprintBestSol(scip, NULL, FALSE) );

   /* frees SCIP data structure */
   SCIP_CALL( SCIPfree(&scip) );

   return SCIP_OKAY;
}


/** main function */
int main(
   int                        argc,
   char**                     argv
   )
{
   SCIP_RETCODE retcode;
   int n;
   int k;

   if( argc != 3 )
   {
      printf("usage: ./bin/firstip [n] [k]\n");
      return EXIT_FAILURE;
   }

   /* read input data */
   n = atoi(argv[1]);
   k = atoi(argv[2]);

   /* stop if n or k are non-positive */
   if( n <= 0 || k <= 0 )
   {
      printf("n and k must be positive integers\n");
      return EXIT_FAILURE;
   }

   /* solve the IP */
   retcode = solveIP(n, k);

   if( retcode != SCIP_OKAY )
      return EXIT_FAILURE;

   return EXIT_SUCCESS;
}

