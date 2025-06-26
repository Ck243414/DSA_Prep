#include<stdio.h>

void swap(int* a, int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void recbubblesort(int arr[], int n){
    if(n==1){
        return;             //base case
    }
    int count=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(&arr[i],&arr[i+1]);
            count++;
        }
    }
    if(count==0){
        return;
    }
    recbubblesort(arr,n-1);
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
    recbubblesort(unsortedarr,len);
    printArr(unsortedarr,len);
    return 0;
}