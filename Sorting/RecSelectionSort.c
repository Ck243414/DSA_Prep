#include <stdio.h>

int findMinIndex(int arr[], int start, int n) {
    if (start == n - 1)
        return start;

    int minIndexRest = findMinIndex(arr, start + 1, n);
    return (arr[start] < arr[minIndexRest]) ? start : minIndexRest;
}

void recursiveSelectionSort(int arr[], int start, int n) {
    if (start >= n - 1)
        return;

    int minIndex = findMinIndex(arr, start, n);

    int temp = arr[start];
    arr[start] = arr[minIndex];
    arr[minIndex] = temp;

    recursiveSelectionSort(arr, start + 1, n);
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int unsortedarr[5] = {24, 12, 45, 22, 13};
    int len = sizeof(unsortedarr) / sizeof(int);

    printArr(unsortedarr, len);
    recursiveSelectionSort(unsortedarr, 0, len);
    printArr(unsortedarr, len);

    return 0;
}
