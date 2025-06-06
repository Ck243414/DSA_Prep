// C program to modify a singly linked list
// By Reversing the 2nd Half Twice
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a linked list iteratively
struct Node* reverse(struct Node* head) {
    
    // Initialize previous, current, and next pointers
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    // Traverse and reverse the linked list
    while (curr != NULL) {
        next = curr->next;
        
        // Reverse the current node's pointer
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Function to modify the linked list
struct Node* modifyTheList(struct Node* head) {
    
    // Returning head if list has only one node
    if (head->next == NULL) return head;

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* mid;

    // Finding the middle node of the linked list
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow;

    // Storing the second half of the list starting
    // after the middle node
    struct Node* reversedList = mid->next;

    // Splitting the list into two halves
    mid->next = NULL;

    // Reversing the second half of the list
    reversedList = reverse(reversedList);

    struct Node* curr1 = head;
    struct Node* curr2 = reversedList;

    // Iterating over both halves of the list 
    // and modifying the values
    while (curr2 != NULL) {
        int x = curr1->data;
        curr1->data = curr2->data - x;
        curr2->data = x;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // Reversing the second half of the list 
    // again and connecting both halves
    mid->next = reverse(reversedList);
    
    return head;
}

// Function to print the linked list
void printList(struct Node* node) {
    struct Node* curr = node;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node* createNode(int new_data) {
    struct Node* new_node 
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main() {
    
    // Create a hard-coded linked list
    // 10 -> 4 -> 5 -> 3 -> 6
    struct Node* head = createNode(10);
    head->next = createNode(4);
    head->next->next = createNode(5);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(6);

    head = modifyTheList(head);

    printList(head);

    return 0;
}