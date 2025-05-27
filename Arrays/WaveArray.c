#include <stdio.h>

// Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to sort array in wave form in O(n) time
void sortInWave(int arr[], int n) {
    for (int i = 0; i < n; i += 2) {
        // If current even index is not the first element and is smaller than the previous
        if (i > 0 && arr[i] < arr[i - 1])
            swap(&arr[i], &arr[i - 1]);

        // If current even index is not the last and is smaller than the next
        if (i < n - 1 && arr[i] < arr[i + 1])
            swap(&arr[i], &arr[i + 1]);
    }
}

// Driver code
int main() {
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortInWave(arr, n);

    printf("Wave array:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}
