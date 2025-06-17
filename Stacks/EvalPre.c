#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FixedStack.h"

int evaluatePrefix(char* exp)
{
    int len = strlen(exp);
    struct Stack* stack = createStack(len);
    if (!stack) return -1;

    // Scan from right to left
    for (int i = len - 1; i >= 0; i--)
    {
        if (isspace(exp[i]))
            continue;

        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
                case '+': push(stack, val1 + val2); break;
                case '-': push(stack, val1 - val2); break;
                case '*': push(stack, val1 * val2); break;
                case '/': push(stack, val1 / val2); break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char exp[] = "-+2*319"; // Equivalent to "2 3 1 * + 9 -" in prefix
    printf("prefix evaluation: %d\n", evaluatePrefix(exp));
    return 0;
}
