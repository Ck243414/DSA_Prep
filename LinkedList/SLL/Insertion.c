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
// time complexity of O(1)
struct Node* InsertBeg(struct Node* head, int newdata){
    struct Node* newnode = newNode(newdata);
    newnode->data=newdata;
    newnode->next=head;
    return newnode;
}

struct Node* InsertEnd(struct Node*current,int newdata){
    struct Node* newnode = newNode(newdata);
    newnode->data=newdata;
    current->next=newnode;
    newnode->next=NULL;
    return newnode;
}
// time complexity of O(n)
struct Node* InsertEndAlt(struct Node* head, int newdata){
    struct Node* newnode = newNode(newdata);
    newnode->data=newdata;
    if(head==NULL){
        return newnode;
    }
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=newnode;
    newnode->next=NULL;
    return newnode;
}

struct Node* InsertSpec(struct Node* head, int newdata, int key) {
    struct Node* newnode = newNode(newdata);
    if (head == NULL) {
        // Cannot insert before a key if the list is empty
        return NULL;
    }
    // Special case: Insert before the head node
    if (head->data == key) {
        newnode->next = head;
        return newnode;
    }
    struct Node* current = head;
    // Traverse until the next node contains the key
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }
    if (current->next == NULL) {
        // Key not found, do not insert
        return head;
    }
    newnode->next = current->next;
    current->next = newnode;
    return head;
}

//Now print the list appropriately