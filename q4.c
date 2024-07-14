#include <stdio.h>
#include<windows.h>
int main(void){
    int pai[] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 9;i>=0;i--){
        int tmp = pai[0];//暂存第一张
        for(int j = 0;j<i;j++){
            pai[j] = pai[j+1];//删掉第二章

        }
        pai[i] = tmp;//放到最后
        for(int j = 0;j<i;j++){
            pai[j] = pai[j+1];
        }
    }
    printf("牌是%d\n",pai[0]);
    //思考题：用两个变量存，第一次j从1开始，前移两次
    system("pause");
    return 0;
}