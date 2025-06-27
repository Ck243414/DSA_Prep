#include<stdio.h>

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortIterative(int arr[], int n) {
    int curr_size;  // size of subarrays to merge: 1, 2, 4, 8 ...
    int left_start; // starting index of left subarray to merge

    // Merge subarrays in bottom-up manner
    for (curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        // Pick starting point of different pairs of subarrays
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // Find ending point of left subarray
            int mid = left_start + curr_size - 1;
            if (mid >= n - 1)
                continue; // skip incomplete pair at end

            // Find ending point of right subarray
            int right_end = left_start + 2 * curr_size - 1;
            if (right_end >= n - 1)
                right_end = n - 1;

            merge(arr, left_start, mid, right_end);
        }
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int unsortedarr[6] = {24, 12, 45, 22, 13, 8};
    int len = sizeof(unsortedarr) / sizeof(int);

    printf("Before Sorting: ");
    printArr(unsortedarr, len);

    mergeSortIterative(unsortedarr, len);

    printf("After Sorting: ");
    printArr(unsortedarr, len);

    return 0;
}
