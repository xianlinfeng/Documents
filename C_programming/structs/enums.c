#include <stdio.h>

#define SCIP_Real double
#define SCIP_BOOL unsingned int
#define TRUE 1
#define FALSE 0

struct Scip
{
    /* INIT */ 
    // SCIP_MEM* mem;
    // SCIP_SET* set;

    /* PROGRAM */
    // SCIP_STAT* stat;
    // SCIP_PROB* origprob;
};
typedef struct Scip SCIP;


enum SCIP_Retcode
{
    SCIP_OKAY = +1,       /* normal termin a tion */
    SCIP_ERROR = 0,       /* u n s p e ci fi e d e r r o r */
    SCIP_NOMEMORY = -1,   /* i n s u f f i c i e n t memory e r r o r */
    SCIP_READERROR = -2,  /* read e r r o r */
    SCIP_WRITEERROR = -3, /* w ri te e r r o r */

};
typedef enum SCIP_Retcode SCIP_RETCODE;

#define SQR(X) ((x) * (x)) // 定义一个功能
#define SCIP_CALL(x) do 
                    {
                        SCIP_RETCODE _restat_;
                        // if( (_restat_ = (x)) != SCIP_OKAY )
                        {
                            SCIPerrorMessage("Error <%d> \n ", _restat_);
                            return _restat_;
                        }
                    } while (FALSE)

SCIP_RETCODE SCIPsolve(SCIP* SCIP);



int main()
{

    return 0;
}