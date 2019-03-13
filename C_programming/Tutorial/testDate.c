#include<stdio.h>

int main(){
    // This program will detect the number of days of the date input by user
    int day, month, year, sum, leap;
    printf("请输入年，月，日，格式为：年，月，日（e.g. 2005，5，6）\n");
    scanf("%d,%d,%d", &year,&month,&day); //格式为 2005，5，6

    switch (month)
    {
        case 1: sum = 0 ; break;
        case 2:sum=31;break;
        case 3:sum=59;break;
        case 4:sum=90;break;
        case 5:sum=120;break;
        case 6:sum=151;break;
        case 7:sum=181;break;
        case 8:sum=212;break;
        case 9:sum=243;break;
        case 10:sum=273;break;
        case 11:sum=304;break;
        case 12:sum=334;break;
        default: printf("data error! \n"); break;
    }

    sum += day;

    if(year%400==0||(year%4==0&&year%100!=0)) {// 判断是不是闰年
        leap=1;
    } else {
       leap=0;
    }
    if(leap==1&&month>2) { // *如果是闰年且月份大于2,总天数应该加一天
        sum++;
    }
    printf("这是这一年的第 %d 天。",sum);
    printf("\n");



}