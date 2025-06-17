#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:  return -1;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void swapParentheses(char *exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

char *infixToPostfix(char *infix) {
    int i, j;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX_EXPR_SIZE];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        } else if (isOperator(infix[i])) {
            while (top > -1 && precedence(stack[top]) > precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    while (top > -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
    return postfix;
}

char *infixToPrefix(char *infix) {
    char revInfix[MAX_EXPR_SIZE];
    strcpy(revInfix, infix);

    reverse(revInfix);
    swapParentheses(revInfix);

    char *postfix = infixToPostfix(revInfix);

    int len = strlen(postfix);
    char *prefix = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(prefix, postfix);
    reverse(prefix);

    free(postfix);
    return prefix;
}

int main() {
    char infix[MAX_EXPR_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_EXPR_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline if present

    char *prefix = infixToPrefix(infix);
    printf("Prefix expression: %s\n", prefix);
    free(prefix);
    return 0;
}
