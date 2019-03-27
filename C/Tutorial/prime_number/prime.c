#include <stdio.h>
#include <math.h>

#include "prime.h"

int primeNo(unsigned int a)
{
    if (a <= 3)
    {
        return 0;
    }

    if (a % 6 != 1 && a % 6 != 5)
    {
        return 1;
    }

    int sq = (int)sqrt(a);

    for (int i = 5; i < sq; i += 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
        {
            return 1;
        }
    }

    return 0;
}