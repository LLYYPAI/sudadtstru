#include <stdio.h>
#include<windows.h>


typedef struct{
    int shenfenzheng;
    int zhanghuyue;
    int zhangdanri;
}Chuhu;


int main(void){
    Chuhu *a = malloc(10*sizeof(Chuhu));
    for(int i = 0;i<10;i++){
        (a+i)->shenfenzheng = 15454454564546+i*3;
        (a+i)->zhanghuyue = 789456+45*i;
        (a+i)->zhangdanri = 12+i;
    }//随机给几个数据

    for(int i = 0;i<10;i++){
        printf("第%d人身份证是%d\n",i+1,(a+i)->shenfenzheng);
        printf("第%d人账户余额是%d\n",i+1,(a+i)->zhanghuyue);
        printf("第%d人月账单日是第%d天\n\n",i+1,(a+i)->zhangdanri);
    }
    free(a);
    
    system("pause");
    return 0;
}