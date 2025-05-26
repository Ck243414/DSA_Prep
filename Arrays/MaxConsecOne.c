#include <stdio.h>

int getMaxConsecutive(int arr[], int n) {
    if (n == 0) return 0;

    int maxCount = 1;
    int currentCount = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount)
                maxCount = currentCount;
            currentCount = 1;
        }
    }

    // Check the last streak
    if (currentCount > maxCount)
        maxCount = currentCount;

    return maxCount;
}

int main() {
    // Example array
    int arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = getMaxConsecutive(arr, n);
    printf("Maximum number of consecutive 1's or 0's is %d\n", result);

    return 0;
}
