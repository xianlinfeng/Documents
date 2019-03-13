#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[1000];
    char* descp;

    strcpy(name, "Xianlin Feng");

    descp = (char *)malloc(200*sizeof(char));
    // descp = (char *)calloc(200,sizeof(char)); // 也可以这样写
    if (descp ==NULL) {
        fprintf(stderr,"Error - unable to allocate required memory \n");
    }
    else
    {
        strcpy(descp,"This is a string for the description!\n");
    }
    printf("Name = %s \n", name);
    printf("Description: %s \n",descp);
    
    // 重新调整内存大小
    descp = realloc(descp, 500*sizeof(char));

    //释放内存、
    free(descp);

    
    return 0;
}