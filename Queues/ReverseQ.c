#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int stack[MAX_SIZE];
int top = -1;

bool is_queue_empty() {
    return front == -1 && rear == -1;
}

bool is_queue_full() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int data) {
    if (is_queue_full()) {
        printf("Error: Queue is full\n");
        return;
    }
    if (is_queue_empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}

int dequeue() {
    if (is_queue_empty()) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}

bool is_stack_empty() {
    return top == -1;
}

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (is_stack_empty()) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void reverse_queue_using_stack() {
    while (!is_queue_empty()) {
        int data = dequeue();
        push(data);
    }

    while (!is_stack_empty()) {
        int data = pop();
        enqueue(data);
    }
}

void print_queue() {
    if (is_queue_empty()) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);

    printf("Original Queue:\n");
    print_queue();

    reverse_queue_using_stack();

    printf("Reversed Queue:\n");
    print_queue();

    return 0;
}
