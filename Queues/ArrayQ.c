#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned cap){
    struct Queue* newq=(struct Queue*)malloc(sizeof(struct Queue));
    newq->capacity=cap;
    newq->front=newq->size=0;
    newq->rear=cap-1;
    newq->array=(int*)malloc(newq->capacity*sizeof(int));
    return newq;
}

int isFull(struct Queue*q){
    return(q->size==q->capacity);
}

int isEmpty(struct Queue*q){
    return(q->size==0);
}

void enqueue(struct Queue*q, int data){
    if(isFull(q)){
        return;
    }
    q->rear=(q->rear+1 )% q->capacity;
    q->array[q->rear]=data;
    q->size=q->size+1;
    printf("%d enqueued to the queue\n", data);
}

int dequeue(struct Queue*q){
    if(isEmpty(q)){
        return INT_MIN;
    }
    int data=q->array[q->front];
    q->front=(q->front+1) %q->capacity;
    q->size=q->size-1;
    return data;
}

int front(struct Queue*q){
    if(isEmpty(q)){
        return INT_MIN;
    }
    return q->array[q->front];
}

int rear(struct Queue* q){
    if(isEmpty(q)){
        return INT_MIN;
    }
    return q->array[q->rear];
}

int main(){
    struct Queue* q=createQueue(5);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    int a=dequeue(q);
    printf("%d dequeud\n",a);
    enqueue(q,60);
    return 0;

}



