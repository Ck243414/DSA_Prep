#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newNode(int data) {
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Function to push an item to stack
void Push(struct StackNode** top, int val) {
    struct StackNode* node = newNode(val);
    node->next = *top;
    *top = node;
    printf("%d Pushed onto stack\n", val);
}

// Function to pop an item from stack
int Pop(struct StackNode** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to return top item from stack
int Peek(struct StackNode* top) {
    if (isEmpty(top)) {
        return INT_MIN;
    }
    return top->data;
}

int main() {
    struct StackNode* top = NULL;

    Push(&top, 10);
    Push(&top, 20);
    Push(&top, 30);

    printf("Current Peek is %d\n", Peek(top));

    int a = Pop(&top);
    printf("%d Popped\n", a);

    printf("Current Peek is %d\n", Peek(top));

    return 0;
}
