#include <stdio.h>
#include<windows.h>
int main(void){
    for(int i = 1;i<=9;i++){
        for(int j = i;j <= 9; j++){
            printf("%d * %d = %d  ",i,j,i*j);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}