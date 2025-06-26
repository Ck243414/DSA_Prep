#include<stdio.h>
#include<stdbool.h>

void swap(int* a, int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubblesort(int arr[], int n){
    int i, j;
    bool swapped;
    for(i=0;i<n-1;i++){
        swapped=false;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
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
    bubblesort(unsortedarr,len);
    printArr(unsortedarr,len);
    return 0;
}