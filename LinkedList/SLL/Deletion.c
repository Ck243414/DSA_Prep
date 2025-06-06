#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
//O(1)
struct Node* deleteFront(struct Node*head){ 
    if(head == NULL){
        return NULL;
    }
    struct Node*temp = head;
    head=head->next;
    free(temp);
    return head;
}
//O(n)
struct Node* deleteEnd(struct Node*head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct Node* secondlast=head;
    while(secondlast->next->next!=NULL){
        secondlast=secondlast->next;
    }
    free(secondlast->next);
    secondlast->next=NULL;
    return head;
}
//O(n)
struct Node* deleteSpec(struct Node*head,int pos){
    struct Node* temp=head;
    struct Node* prev=NULL;
    if(temp==NULL){
        return head;               //Case 1
    }
    if(pos==1){
        head=head->next;           //Case 2
        free(temp);
        return head;
    }
    for(int i=0;temp!=NULL && i<pos;i++){
        prev=temp;                 //Case 3
        temp=temp->next;
    }
    if(temp!=NULL){
        prev->next=temp->next;
        free(temp);
    }
    else{
        printf("Position not found");
    }
    return head;
}
void printlist(struct Node*head){
    while(head !=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}
int main(){
    int pos;
    struct Node* head=newNode(10);
    head->next=newNode(20);
    head->next->next=newNode(30);
    head->next->next->next=newNode(40);
    printlist(head);
    printf("\n");
    //head=deleteFront(head);
    //head=deleteEnd(head);
    printf("Enter position to delete:");
    scanf("%d",&pos);
    head=deleteSpec(head,pos);
    printlist(head);
    return 0;
}