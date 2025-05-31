//Removing all occurrences of entered element in O(n) time
#include<stdio.h>

int removeElement(int arr[], int n , int element){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=element){
            arr[j]=arr[i];
            j++;
        }
    }
    return j;
}

int main(){
    int arr[10]={1,4,3,2,5,3,4,3,2,3};
    int element;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter the element to be removed:");
    scanf("%d",&element);
    int count= removeElement(arr, n,element);
    printf("The number of elements in the array not equal to the entered element are: %d",count);
    return 0;
}