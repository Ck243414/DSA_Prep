#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1= m-l+1;
    int n2=r-m;
    int L[n1] ,R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i++];
        }
        else{
            arr[k]=R[j++];
        }
        k++;
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int unsortedarr[6]={24,12,45,22,13,8};
    int len=sizeof(unsortedarr)/sizeof(int);
    printArr(unsortedarr,len);
    mergeSort(unsortedarr,0, len-1);
    printArr(unsortedarr,len);
    return 0;
}