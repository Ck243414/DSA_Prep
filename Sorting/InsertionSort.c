#include<stdio.h>

void insertionsort(int arr[], int n){
    for(int i=1;i<n;++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int unsortedarr[5]={24,12,45,22,13};
    int len=sizeof(unsortedarr)/sizeof(int);
    printArr(unsortedarr,len);
    insertionsort(unsortedarr,len);
    printArr(unsortedarr,len);
    return 0;
}