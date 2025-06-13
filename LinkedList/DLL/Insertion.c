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
//O(1)
struct Node* insertBeg(struct Node* head, int startdata){
    struct Node* newnode=newNode(startdata);
    newnode->next=head;
    if(head!=NULL){
        head->prev= newnode;
    }
    return newnode;
}
struct Node* insertEnd(struct Node*head, int enddata){
    struct Node* newnode=newNode(enddata);
    if(head==NULL){
        head=newnode;
    }
    else{
        struct Node* current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newnode;
        newnode->prev=current;
    }
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
    head->next->next->next->next=head->next->next->next->prev;
    printList(head);
    printf("\n");
    head=insertBeg(head,1);
    printList(head);
    printf("\n");
    head=insertEnd(head,6);
    printList(head);
    return 0;
}
