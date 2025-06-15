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
struct Node* delSpec(struct Node* head, int pos){
    if(head==NULL){
        return head;
    }
    if(pos==1){
        struct Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct Node* current =head;
    for(int i=1;i<pos&& current!=NULL;++i){
        current=current->next;
    }
    if(current==NULL){
        printf("Out of bounds");
        return head;
    }
    if(current->prev!=NULL){
        current->prev->next=current->next;
    }
    if(current->next!=NULL){
        current->next->prev=current->prev;
    }
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
    int position=1;
    head=delSpec(head,position);
    printList(head);
    return 0;
}
