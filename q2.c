#include <stdio.h>
#include<windows.h>
int main(void){
    int n = 4567890;
    int ans = 0;
    int weishu = 0;
    while(n){
        ans*= 10;
        ans += n%10;
        n /= 10;
        weishu ++;
    }
    if (!n){
        printf("λ��1\n");
    }
    else{
        printf("λ��%d\n",weishu);
    }
    printf("������%d\n",ans);

    system("pause");
    return 0;
}