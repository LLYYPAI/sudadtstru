#include <stdio.h>
#include<windows.h>
int main(void){
    int pai[] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 9;i>=0;i--){
        int tmp = pai[0];//�ݴ��һ��
        for(int j = 0;j<i;j++){
            pai[j] = pai[j+1];//ɾ���ڶ���

        }
        pai[i] = tmp;//�ŵ����
        for(int j = 0;j<i;j++){
            pai[j] = pai[j+1];
        }
    }
    printf("����%d\n",pai[0]);
    //˼���⣺�����������棬��һ��j��1��ʼ��ǰ������
    system("pause");
    return 0;
}