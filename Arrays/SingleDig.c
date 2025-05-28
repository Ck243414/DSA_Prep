/* // C program to find the digit sum by 
// repetitively Adding its digits O(log n)

#include <stdio.h>

int singleDigit(int n) {
    int sum = 0;

    // Repetitively calculate sum until
    // it becomes single digit
    while (n > 0 || sum > 9) {

        // If n becomes 0, reset it to sum 
        // and start a new iteration.
        if (n == 0) {
            n = sum;
            sum = 0;
        }

        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n = 1234;
    printf("%d", singleDigit(n));
    return 0;
}
 */
#include <stdio.h>

// Function to compute the digital root using modulo 9 trick
int digitalRoot(int n) {
    if (n == 0)
        return 0;
    else if (n % 9 == 0)
        return 9;
    else
        return n % 9;
}

int main() {
    int n;

    // Example input
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = digitalRoot(n);
    printf("The digital root (single-digit sum) of %d is: %d\n", n, result);

    return 0;
}
