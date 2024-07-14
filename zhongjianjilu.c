#include <stdio.h>
#include<windows.h>
typedef struct{
    int data;
    int next;
}Lin;

int main(void){
    Lin *a = malloc(5*sizeof(Lin));
    a[0].data = 100; a[0].next = 4;
    a[1].data = 400; a[1].next = 3;
    a[2].data = 300; a[2].next = 1;
    a[3].data = 500; a[3].next = NULL;
    a[4].data = 200; a[4].next = 2;
    a[5].data = NULL; a[5].next = NULL;

    int len = 1;
    int i = 0;
    int b[5];
    while(a[i].next){
        b[i] = a[i].data;
        printf("%d\n",a[i].next);
        i = a[i].next;
        len++;
    }
    
    printf("长度%d\n",len);
    printf("中间数%d\n",(len%2)?b[len/2]:(b[len/2]+b[len/2-1])/2);

    system("pause");
    return 0;
}