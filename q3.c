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
    }//�������������

    for(int i = 0;i<10;i++){
        printf("��%d�����֤��%d\n",i+1,(a+i)->shenfenzheng);
        printf("��%d���˻������%d\n",i+1,(a+i)->zhanghuyue);
        printf("��%d�����˵����ǵ�%d��\n\n",i+1,(a+i)->zhangdanri);
    }
    free(a);
    
    system("pause");
    return 0;
}