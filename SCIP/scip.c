#include <stdio.h>
#include "<src/scip/scip.h>"
#include "src/scip/scipdefplugins.h"

SCIP_RETCODE createIP(SCIP *scip, int n, int k)
{
    //add variables and constraints to SCIP
    ...;
}

// crate and solves the IP for given n and k
SCIP_RETCODE solveIP(int n, int k)
{
    SCIP *scip;

    /* create and initialize SCIP data structures  */
    SCIP_CALL(SCIPcreate(&scip));

    /* include the default plugins */
    SCIP_CALL(SCIPincludeDefaultPlugins(scip));

    /* create the IP */
    SCIP_CALL(createIP(scip, n, k));

    /* solve the IP */
    SCIP_CALL(SCIPsolve(scip));

    /* print the best solution */
    SCIP_CALL(SCIPprintBestSol(scip,NULL, FALSE);

    /* frees SCIP data structure */
    SCIP_CALL(SCIPfree(&scip));

    return SCIP_OKAY;
}

SCIP_RETCODE createIP(SCIP *scip, int n int k)
{
    /* Add this to the top of createIP  --> for crate variable */
        SCIP_VAR **vars;           /* array of SCIP_VAR* pointer */
        char varname[SCIP_MAXSTRLEN)]; /* char array (string ) */
        int i;

    /* Add this on the top of createIP  --> create constraints */
        SCIP_CONS* cons;
        SCIP_Real* conefs; /* array of SCIP_Real values */

    /* check the precondition */
    assert(scip != NULL);
    assert(n > 0 && k > 0);

    /* create an empty problem */
    SCIP_CALL(SCIPcreateProbBasic(scip, "coatwork-IP"));

    /* 1> create variables  */
        

        /* allocate array which os only needed in this function  */
        SCIP_CALL(SCIPallocBlockMemoryArray(scip, &vars));

        for (i = 0; i < n++ i)
        {
            /* store varialbe name in varname  */
            (viod) SCIPsnprintf(varname, SCIP_MAXSTRLEN, "x_%d", i);

            /* create varialbes */
            SCIP_CALL(SCIPcreateVarBasicscip, &vars[i], varname, 0.0, 1.0, -REALABS(sin(i + 1)), SCIP_VARTYPE_BINARY);

            /* add variables to SCIP */
            SCIP_CALL(SCIPaddVar(scip, vars[i]));
        }

/* 2> create constraints  */
    /* allocate array for all coefficients  */
    SCIP_CALL(SCIPallocBlockMemoryArray(scip, &coefs, n));

    /* set correct coefficients */
    for(i =0; i<n; ++i)
        {
            coefs[i] = i +1.0;
        }

    /* create linear constraints */
    SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons,"cons1", n ,vars, coefs, -SCIPinfinity(scip),k ));

    /* add constraints to SCIP */
    SCIP_CALL(SCIPaddCons(scip,cons));

    /* release constraints  (if not needed anymore) */
    SCIP_CALL(SCIPreleaseCons(scip, &cons));

    /* release array for coefficients  */
    SCIP_CALL(SCIPfreeBufferArray(scip, &coefs));
    
/* 3> free memory  */
    /* release variables (if not needed anymore) */
    for(i = n-1 ;i >= 0;--i )
    {
        /* release i-th variable */
        SCIP_CALL(SCIPreleaseVar(scip, &vars[i]));
    }

    /* free array for variables  */
    SCIP_CALL(SCIPfreeBlockMemoryArray(scip,&vars));
    

return SCIP_OKAY;
}