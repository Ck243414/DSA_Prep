#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4};  // increase array size to 5
    int i;
    int element = 5;
    int pos = 2;

    // Shift elements to the right
    for(i = 4; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[pos] = element;

    // Print the array
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
