//Find Product of max 3 elements in an array with time complexity O(n)
#include<stdio.h>
#include<limits.h>

int getTripletProduct(int arr[],int n){
    if(n<3){
        printf("Less than 3 elements");
        return -1;
    }
    int maxA=INT_MIN,maxB=INT_MIN,maxC=INT_MIN;
    int minA=INT_MAX,minB=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>maxA){
            maxC=maxB;
            maxB=maxA;
            maxA=arr[i];
        }
        else if(arr[i]!=maxA && arr[i]>maxB){
            maxC=maxB;
            maxB=arr[i];
        }
        else if(arr[i]!=maxA && arr[i]>maxC){
            maxC=arr[i];
        }
        if(arr[i]<minA){
            minB=minA;
            minA=arr[i];
        }
        else if(arr[i]<minB && arr[i]>minA){
            minB=arr[i];
        }
    }
    int prod1,prod2;
    prod1=maxA*maxB*maxC;
    prod2=minA*minB*maxA;
    int product=(prod1>prod2)? prod1 : prod2;
    return product;
}
int main(){
    int arr[7]={2,4,-3,5,1,8,-9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int product=getTripletProduct(arr,n);
    printf("The maximum product of triplets is %d",product);
}