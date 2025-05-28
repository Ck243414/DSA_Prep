// For integer return type and O(n)
/* #include<stdio.h>

int addone(int arr[],int n){
    int sum=0;
    for(int i= 0;i<n;i++){
        sum= 10*sum+ (arr[i]);
    }
    return sum+1;
}

int main(){
    int arr[3] = {9,9,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num = addone(arr,n);
    printf("The number is %d",num);
} */

// for array return and O(n)
#include <stdio.h>

void addOne(int arr[], int n) {
    int carry = 1;  // we start by adding 1
    for (int i = n - 1; i >= 0; i--) {
        int sum = arr[i] + carry;
        arr[i] = sum % 10;
        carry = sum / 10;
    }

    // If there's still a carry, we need to resize and shift the array
    if (carry) {
        printf("Result: %d", carry);
    }
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Input: ");
    for (int i = 0; i < n; i++) printf("%d", arr[i]);
    printf("\n");

    printf("Output: ");
    addOne(arr, n);
    return 0;
}
