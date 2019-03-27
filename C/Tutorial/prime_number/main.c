#include <stdio.h>
#include <stdlib.h>

int main()
{
    int range = 9999;
    int i,j, prime[range + 1 ];
    prime[0] = prime[1] = 1;
    for( i= 2; i < range; i++){
        prime[i] = 0;
    }
    int number = 1;
    for(i=2; i < range;i++){
        if(prime[i] == 0){
            for( j = i*2; j<range;j+=i){
                prime[j] =1;
            }
            printf("第%d个： %d \n",number,i);
            number++;
        }
    }
    return 0;
}
