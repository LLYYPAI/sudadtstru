#include<iostream>
using namespace std;
#define MAX 100
typedef struct{
    int data[MAX];
    int length;
}Sqlist;
void Init_Sqlst(Sqlist *&L,int a[],int n){
    L = (Sqlist*)malloc(sizeof(Sqlist));
    for(int i = 0;i<n;i++){
        L->data[i] = a[i];
    }
    L->length = n;
}
Sqlist *sortSQ(Sqlist *L1,Sqlist *L2,int na,int nb){
    Sqlist *L3 = (Sqlist*)malloc(sizeof(Sqlist));
    int i = 0; int j = nb-1;
    while(i!=na && j != -1){
        if(L1->data[i]<L2->data[j]){
            L3->data[i+nb-1-j] = L1->data[i];
            i++;
            }
        else{
            L3->data[i+nb-1-j] = L2->data[j];
            j--;
        }   
    }
    if (i<na){
        for(i = nb+i;i<na+nb;i++){
            L3->data[i] = L1->data[i-nb];
        }
    }
    if(j!=-1){
        for(;j>=0;j--){
            L3->data[na+nb-1-j] = L2->data[j];
        }
    }
    return L3;
}

int main(void){
    Sqlist *L1; Sqlist *L2;
    int a[] = {2,5,5,7,9,23,45,67,89,100}; int na = 10;
    int b[] = {212,122,96,75,55,32,19,2,0}; int nb = 9;
    Init_Sqlst(L1,a,na);Init_Sqlst(L2,b,nb);
    Sqlist *L = sortSQ(L1,L2,na,nb);
    for(int i = 0; i<na+nb;i++){
        printf("%d ",L->data[i]);
    }
    system("pause");
    return 0;
}