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
        printf("位数1\n");
    }
    else{
        printf("位数%d\n",weishu);
    }
    printf("倒过来%d\n",ans);

    system("pause");
    return 0;
}