#include<stdio.h>

void selectionsort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
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
    selectionsort(unsortedarr,len);
    printArr(unsortedarr,len);
    return 0;
}