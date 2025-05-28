#include<stdio.h>

int Stock(int arr[], int n){
    int min=arr[0];
    int res=0;
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]-min>res){
            res=arr[i]-min;
        }
    }
    return res;
}

int main(){
    int arr[5]={9,7,5,4,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    int profit = Stock(arr,n);
    if(profit>0){
        printf("The resulting profit is %d",profit);
    }
    else{
        printf("There is no profit");
    }
}