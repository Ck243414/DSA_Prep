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

void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* insertSpec(struct Node* head, int position,int newdata){
    struct Node* newnode=newNode(newdata);
    if(position==1){
        newnode->next=head;
        if(head!=NULL){
            head->prev=newnode;
        }
        head=newnode;
        return head;
    }
    struct Node*current=head;
    for(int i=1;i<position-1 && current!=NULL; ++i){
        current=current->next;
    }
    if(current==NULL){
        printf("position out of bounds");
        free(newnode);
        return head;
    }
    newnode->prev=current;
    newnode->next=current->next;
    current->next=newnode;
    if(newnode->next!=NULL){
        newnode->next->prev=newnode;
    }
    return head;
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
    int pos,edata;
    printf("Enter the position to insert and data:");
    scanf("%d %d", &pos, &edata);
    head=insertSpec(head,pos,edata);
    printList(head);
    return 0;
}