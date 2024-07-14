#include<stdio.h>
#include<windows.h>
int func(int n){
    int cur = 1;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cur *= i;
        sum += cur;
    }
    return sum;
}//O(n)


int main(void){
    int n = 5;
    printf("从1到%d阶乘相加的结果是%d\n",n,func(n));
    system("pause");
    return 0;
}