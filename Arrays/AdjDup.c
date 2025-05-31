#include <stdio.h>

// Function to count occurrences of k in arr[0..n-1]
int countK(int arr[], int n, int k) {
    int count = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == k)
            count++;
    return count;
}

// Function to duplicate all occurrences of k in-place
void duplicateK(int arr[], int n, int k) {
    int cnt = countK(arr, n, k);
    int write_idx = n + cnt - 1;
    int curr = n - 1;

    // Traverse from the end and duplicate k
    while(curr >= 0 && write_idx >= 0) {
        // Place current element at write_idx if within bounds
        if(write_idx < n)
            arr[write_idx] = arr[curr];
        write_idx--;

        // If current element is k, duplicate it
        if(arr[curr] == k) {
            if(write_idx < n)
                arr[write_idx] = k;
            write_idx--;
        }
        curr--;
    }
}

int main() {
    int arr[] = {1, 0, 2, 3, 0, 4, 5, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 0;

    duplicateK(arr, n, k);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
