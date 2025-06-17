#include<stdio.h>
#include<stdlib.h>

// Structure for Queue
struct Queue {
    int front, rear;
    int capacity;
    int *array;
};

// Function to create a queue of given capacity
struct Queue *createQueue(int capacity) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    if (queue->front == -1)
        queue->front = queue->rear;
}

// Function to remove an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue))
        return -1e9+1;
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

// Function to implement stack using two queues
void push(struct Queue *queue1, struct Queue *queue2, int item) {
    enqueue(queue1, item);
}

// Function to implement pop operation of stack
int pop(struct Queue *queue1, struct Queue *queue2) {
    if (isEmpty(queue1))
        return -1e9+1;
    while (queue1->front != queue1->rear) {
        int item = dequeue(queue1);
        enqueue(queue2, item);
    }
    int item = dequeue(queue1);
    struct Queue *temp = queue1;
    queue1 = queue2;
    queue2 = temp;
    return item;
}

// Driver code
int main() {
    struct Queue *queue1 = createQueue(100);
    struct Queue *queue2 = createQueue(100);
    push(queue1, queue2, 10);
    push(queue1, queue2, 20);
    push(queue1, queue2, 30);
    printf("%d popped from stack\n", pop(queue1, queue2));
    printf("%d popped from stack\n", pop(queue1, queue2));
    return 0;
}