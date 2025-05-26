#include<stdio.h>
#include<limits.h>

int getSecondSmallest(int arr[],int n){
    int smallest=INT_MAX;
    int secondsmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            secondsmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<secondsmallest){
            secondsmallest=arr[i];
        }
    }
    return secondsmallest;
}

int main(){
    int arr[6] = {1,24,56,22,45,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s=getSecondSmallest(arr,n);
    printf("Second smallest number is %d",s);
}