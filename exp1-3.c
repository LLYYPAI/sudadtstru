#include<stdio.h>
#include<windows.h>
int method_1(int n){
    if(n==1){return 0;}
    int count = n;
    int *a = calloc(n+1, sizeof(int));
    //�ų�ż��
    a[0] = 1;a[1] = 1 ;a[2]=0;//��һ������������
    for(int i = 2; i*i <= n; i++){
        if(a[i]){continue;}
        for(int j = 2;i*j<=n;j++){
            if(a[i*j]){continue;}
            a[i*j] = 1;//i*jΪ������
            count--;
        }
        
    }
    free(a);
    return count-1;
    
}//O(nlgn)
int method_2(int n){
    int count = 0;
    for(int i = 1;i<=n;i++){
        int flag = 1;//Ĭ��������
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag= 0;
                break;
            }
        }
        if(flag){
            count++;
        }
    }
    return count-1;
}//O(n**1.5)

int main(void){
    int n = 10000;
    printf("�õ�һ�ַ�����1��%dһ����%d������\n",n,method_1(n));
    printf("�õڶ��ַ�����1��%dһ����%d������\n",n,method_2(n));
    system("pause");
    return 0;
}