#include <stdio.h>

#define SCIP_REAL double
#define SCIP_BOOL unsigned int
#define TRUE 1
#define FALSE 0


#define SCIP_CALL(x) do
{
    SCIP_RETCODE _restat_;
    if( (_restat_ = (x)) != SCIP_OKAY)
    {
        SCIPerrorMessage("Error <%d>\n",_restat_ );
        return _restat_
    }
} while (FALSE)


struct Scip
{
    /* INIT */
    SCIP_MEM* men;
    SCIP_SET* set;
    SCIP_INTERRUPT* interrupt;

    /* PROBLEM */
    SCIP_STAT* stat;
    SCIP_PROB* origprob;
    SCIP_PROMAL* origprimal;
    ...;

};

typedef struct Scip SCIP;


enum SCIP_Retcode 
{
    SCIP_OKAY = +1,
    SCIP_ERROR  =0,
    SCIP_NOMEMORY = -1,
    SCIP_READERROR = -2,
    SCIP_WRITEERROR = -3,
};
typedef enum SCIP_Retcode SCIP_RETCODE;

SCIP_RETCODE SCIPsolve(SCIP* scip);

SCIP_RETCODE foo(SCIP* scip)
{
    SCIP_CALL(SCIPsolve(scip));
    return SCIP_OKAY;
}



int main(){
    int e[9];
    int* b;
    int i;

    for(i = 0; i <9;++i)
    {
        e[i] = i;
    }

    b = e;
    b = e[0];
    

   return 0;
}



