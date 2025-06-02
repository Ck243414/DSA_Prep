#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
// Searching in O(n) time can be done recursively
bool search(struct Node*head , int val){
    struct Node* current =head;
    while(current != NULL){
        if(current->data == val){
            return 1;
        }
        current=current->next;
    }
    return 0;
}
int main(){
    struct Node* list=newNode(10);
    list->next=newNode(20);
    list->next->next=newNode(30);
    list->next->next->next=newNode(40);
    int key=30;
    if(search(list,key)){
        printf("Key found in linked list");
    }
    else{
        printf("Not found");
    }
}

// for length just maintain counter and increment 
// that counter till value of head becomes null