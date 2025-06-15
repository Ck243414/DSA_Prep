#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};

struct Node* newNode(int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct Node* delBeg(struct Node* head){
    if(head==NULL){
        return NULL;
    }
    struct Node* temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    free(temp);
    return head;
}
struct Node* delEnd(struct Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct Node* current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->prev->next=NULL;
    free(current);
    return head;
}

void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
int main(){
    struct Node*head=newNode(2);
    head->next=newNode(3);
    head->next->prev=head;
    head->next->next=newNode(4);
    head->next->next->prev=head->next;
    head->next->next->next=newNode(5);
    head->next->next->next->prev=head->next->next;
    printList(head);
    printf("\n");
    head=delBeg(head);
    printList(head);
    printf("\n");
    head=delEnd(head);
    printList(head);
    return 0;
}
