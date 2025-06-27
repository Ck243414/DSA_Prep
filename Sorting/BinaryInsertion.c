#include<stdio.h>

int BinarySearch(int arr[],int item, int low, int high){
    if(low > high){
        return low;
    }
    int mid=(low+high)/2;
    if(item==arr[mid]){
        return mid+1;
    }
    if(item>arr[mid]){
        return BinarySearch(arr, item, mid+1, high);
    }
    else{
        return BinarySearch(arr, item, low, mid-1);
    }
}

void InsertionSort(int arr[], int n){
    int i, j, key , position;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        position=BinarySearch(arr, key, 0, j);
        while(j>=position){
            arr[j+1]=arr[j];
            j--;
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
    InsertionSort(unsortedarr,len);
    printArr(unsortedarr,len);
    return 0;
}