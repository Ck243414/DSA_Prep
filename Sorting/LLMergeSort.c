#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node* splitList(struct Node* head){
    struct Node*fast=head;
    struct Node*slow=head;
    while( fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        if(fast!=NULL){
            slow=slow->next;
        }
    }
    struct Node* temp=slow->next;
    slow->next=NULL;
    return temp;
}

struct Node* merge(struct Node*first, struct Node*second){
    if(first==NULL) return second;
    if(second==NULL) return first;
    if(first->data<second->data){
        first->next=merge(first->next,second);
        return first;
    }
    else{
        second->next=merge(first,second->next);
        return second;
    }
}

struct Node* mergeSort(struct Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node* second=splitList(head);
    head=mergeSort(head);
    second=mergeSort(second);
    return merge(head,second);
}

struct Node* printList(struct Node*head){
    struct Node* current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
    return head;
}

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

int main(){
    struct Node*head=createNode(20);
    head->next=createNode(10);
    head->next->next=createNode(80);
    head->next->next->next=createNode(30);
    head->next->next->next->next=createNode(40);
    head->next->next->next->next->next=createNode(70);
    head->next->next->next->next->next->next=createNode(50);
    head=printList(head);
    head=mergeSort(head);
    head=printList(head);
    return 0;
}