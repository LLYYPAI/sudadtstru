#include<iostream>
#include<windows.h>

void ShellSort(int a[],int n){
    int i,j,d;
    int tmp;d = n/2;
    while(d>0){
        for(i=d;i<n;i++){
            tmp = a[i];
            j = i-d;
            while(j>=0&&tmp<a[j]){
                a[j+d]=a[j];
                j=j-d;
            }
            a[j+d]=tmp;
        }
        d = d/2;
    }
}
void Disparr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int partition(int arr[],int s,int t){
    int i = s;int j = t;
    int base = arr[i];
    while(i<j){
        while(j>i&&arr[j]>=base){
            j--;
        }
        if(j>i){
            arr[i]=arr[j];
            i++;
        }
        while(j>i&&arr[i]<=base){
            i++;
        }
        if(j>i){
            arr[j]=arr[i];
            j--;
        }
    }
    arr[i] = base;
    return i;
}
void QuickSort(int arr[],int s,int t){
    int i;
    if(s<t){
        i = partition(arr,s,t);
        QuickSort(arr,s,i-1);
        QuickSort(arr,i+1,t);
    }
}




int main(){
    int N = 10;
    int a[10] = {6,8,9,4,5,6,2,1,7,50};
    int b[10] = {6,8,9,4,5,6,2,1,7,50};
    ShellSort(a,10);
    Disparr(a,10);
    QuickSort(b,0,10);
    Disparr(b,10);
    system("pause");
    return 0;
}