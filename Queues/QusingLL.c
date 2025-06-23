#include<stdio.h>
#include<stdlib.h>

struct QNode{
    int data;
    struct QNode* next;
};

struct Queue{
    struct QNode* front, *rear;
};

struct QNode* newNode(int newdata){
    struct QNode* newnode=(struct QNode*)malloc(sizeof(struct QNode));
    newnode->data=newdata;
    newnode->next=NULL;
    return newnode;
}

struct Queue* createQueue(){
    struct Queue* newq=(struct Queue*)malloc(sizeof(struct Queue));
    newq->front=newq->rear=NULL;
    return newq;
}

void enQueue(struct Queue* q, int new){
    struct QNode* node=newNode(new);
    if(q->rear==NULL){
        q->front=q->rear=node; //If queue is empty then this
    }
    q->rear->next=node;
    q->rear=node;
}
void deQueue(struct Queue*q){
    if(q->front==NULL){
        return;   // empty queue
    }
    struct QNode* temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
}
// time complexity for enqueue and dequeue is O(1) as ptrs are changing

int main(){
    struct Queue* q=createQueue();
    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);
    enQueue(q,50);
    printf("Front of the queue is %d\n",q->front->data);
    printf("Rear of the queue is %d\n", q->rear->data);
    deQueue(q);
    deQueue(q);
    enQueue(q,60);
    printf("Front of the queue is %d\n",q->front->data);
    printf("Rear of the queue is %d\n", q->rear->data);
    return 0;
}
