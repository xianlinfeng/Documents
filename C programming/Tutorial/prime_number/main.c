#include <stdio.h>

int main()
{
    long range = 999999 + 47000;
    long i,j;
    long prime[range + 1 ]; 
    prime[0] = prime[1] = 1;
    for( i= 2; i < range; i++){
        prime[i]=0;
    }
    for(i=2; i < range;i++){
        if(prime[i] == 0){
            for( j = i*2; j<range;j+=i){
                prime[j]=1;
            }
            printf("%ld \n",i);
        }
    }
    return 0;
}

