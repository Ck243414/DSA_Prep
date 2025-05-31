//Remove Duplicates of all elements in O(n) time given the array is sorted O(1) space
#include<stdio.h>

int remDup(int arr[], int n){
    int index=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            arr[index]=arr[i];
            index++;
        }
    }
    return index;
}

int main(){
    int arr[6]={1,2,3,6,6,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=remDup(arr,n);
    printf("%d distinct elements in array",count);
    return 0;
}