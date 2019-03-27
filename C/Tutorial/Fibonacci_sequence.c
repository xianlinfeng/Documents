#include <stdio.h>
//打印前30个斐波那契数列

int main(){
    int f1=0,f2=1,i,tem;
    for(i=1;i<= 30;i++){
        printf("%18d \n",f2);
        tem = f2;
        f2 = f1 + f2 ;
        f1 = tem;
    }
    
    return 0;
}