#include <stdio.h>

#define N 10000
// 如果一个数恰好等于它的因子之和，那么这个数被称作“完数” complete number

int main(){
    int arr[256];

    for(int n=3;n<=N;n++){
        int s = n/2,k=0,sum;
        sum = arr[0]= 0;
        for (int i=2; i<= s; i++){
            if(n%i == 0){
                arr[++k] = i;    
                sum += i;
            }
        }

        if (n==sum) {
            printf("%d = %d ", n,arr[0]);
            for(int j = 1;j <= k; j++){
                printf(" + %d", arr[j]);
            }
            printf("\n");
        }
        

    }


    return 0;
}