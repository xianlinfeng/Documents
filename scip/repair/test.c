#include <stdio.h>
#include <stdlib.h>

int main(
    int argc,
    char **argv)
{
    int j = 0;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        printf("The value of i is %d\n", i);
        j++;
    }
    printf("The value of j is %d \n", j);
    return 0;
}