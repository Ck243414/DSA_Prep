// C program to reverse every sub-array formed by
// consecutive k elements
#include <stdio.h>

// Function to reverse every sub-array formed by
// consecutive k elements
void reverse(int arr[], int n, int k)
{
    for (int i = 0; i < n; i += k)
    {
        int left = i;
        int right;
        // to handle case when k is not multiple of n
        if(i+k-1<n-1)
        right = i+k-1;
        else
        right = n-1;

        // reverse the sub-array [left, right]
        while (left < right)
            {
                // swap
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }

    }
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;

    int n = sizeof(arr) / sizeof(arr[0]);

    reverse(arr, n, k);

    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);

    return 0;
}
