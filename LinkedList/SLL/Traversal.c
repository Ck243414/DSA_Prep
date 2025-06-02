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

// time complexity O(n) can also be done using recursion in same time
void TraverseList(struct Node* head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    struct Node* list=newNode(10);
    list->next=newNode(20);
    list->next->next=newNode(30);
    list->next->next->next=newNode(40);
    TraverseList(list);
}
