#include <stdio.h>
#include <stdlib.h>

int main(
    int argc,
    char** argv
)
{
    int a = 100;
    int b = 101;
    int **p;
    // p = (int *)malloc( 2 * sizeof(int) );
    p[0] = &a;
    p[1] = &b;

    printf("%d\n",*p[0]);

    return 0;
}