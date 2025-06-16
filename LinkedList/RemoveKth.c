// C program to delete every k-th Node of
// a singly linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to remove every kth node in the linked list
struct Node* deleteK(struct Node* head, int k) {
  
    // If list is empty or k is 0, return the head
    if (head == NULL || k <= 0) 
        return head;
  
    struct Node* curr = head;
    struct Node* prev = NULL;

    int count = 0;

    while (curr != NULL) {
        count++;

        // If count is a multiple of k, remove 
        // current node
        if (count % k == 0) {
          
            // skip the current node
            if (prev != NULL) {
                prev->next = curr->next;
            } 
            else {
         
                head = curr->next;
            }
            free(curr);
            curr = prev != NULL ? prev->next : head;
        } 
        else {
          
            // Update previous node pointer only if
            // we do not remove the node
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

void printList(struct Node* node) {
   struct Node* curr = node;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* createNode(int new_data) {
    struct Node* new_node = 
        (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}


int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    int k = 2;
    head = deleteK(head, k);

    printList(head);

    return 0;
}