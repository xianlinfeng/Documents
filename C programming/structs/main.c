#include <stdio.h>

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

struct Data{
    double a;
    int b;
} ;

typedef struct Data DATA;

void foo1(DATA d)
{
    d.a = 1;
}

void foo2(DATA* d){
    (*d).a = 5;
}

int main() 
{
    DATA d;
    DATA* p;
    
    d.a = 0;
    d.b = -1;
    p = &d;
    foo1(d);
    printf("foo1 result = %f \n", d.a);


    foo2(&d);
    printf("foo2 result = %f \n", d.a);


    // (*p).a = 2.0;
    // p->a = 3.0;
    // printf("%e %d \n", d.a, d.b);

    return 0;
}