//Find Second Largest element in array with time complexity O(n)
#include<stdio.h>

int getSecondLargest(int arr[],int n){
    int largest=-1, secondlargest =-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }
        else if(arr[i]!=largest && arr[i]>secondlargest){
            secondlargest=arr[i];
        }
    }
    return secondlargest;
}

int main(){
    int arr[6] = {1,24,56,22,45,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s = getSecondLargest(arr,n);
    printf("Second largest element in the array is %d",s);
}
