#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* newNode(int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void forwTrav(struct Node*head){
    struct Node*current=head;
    while(current!=NULL){
        printf("%d",current->data);
        current=current->next;
    }
}
void revTrav(struct Node*tail){
    struct Node*current=tail;
    while(current!=NULL){
        printf("%d",current->data);
        current=current->prev;
    }
}
int main(){
    struct Node*head=newNode(10);
    struct Node*second=newNode(20);
    struct Node*third=newNode(30);
    struct Node*fourth=newNode(40);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    forwTrav(head);
    printf("\n");
    revTrav(fourth);
    return 0;
}