#include <stdio.h>
#include <assert.h>

#include "one.h"

double sumup(int a, int b)
{
    int i;
    double sum = 0.0;
    assert(a >= 0 && b >= 0);

    if (b < a)
    {
        int t;
        t = a; a = b; b = t;
    }

    assert(a <= b);

    for ( int i = a; i <= b; i++)
    {
        sum += i;
    }

    return sum;

}
