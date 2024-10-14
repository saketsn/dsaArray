//Q-02 -- Create a double-linked list with duplication, remove the duplicate elements and display the list
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the doubly linked list
void printList(struct Node* ptr) {
    while (ptr != NULL) {
        printf(" <- %d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to remove duplicate nodes with a given value
struct Node* removeDuplicate(struct Node* head, int val) {
    struct Node* current = head;
    struct Node* temp;

    while (current != NULL) {
        if (current->data == val) {
            temp = current;

            // Adjusting pointers to remove the node
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else { // If it's the head node
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            current = current->next; // Move to the next node
            free(temp); // Free the duplicate node
        } else {
            current = current->next; // Move to the next node
        }
    }
    return head;
}

// Main function
int main() {
    // Creating and initializing nodes
    struct Node* N1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* N2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* N3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* N4 = (struct Node*)malloc(sizeof(struct Node));

    N1->data = 11;
    N1->next = N2;
    N1->prev = NULL;

    N2->data = 22;
    N2->next = N3;
    N2->prev = N1;

    N3->data = 22;
    N3->next = N4;
    N3->prev = N2;

    N4->data = 33;
    N4->next = NULL;
    N4->prev = N3;

    printf("Original doubly linked list with duplicate elements:\n");
    printList(N1);

    // Removing duplicates with value 22
    N1 = removeDuplicate(N1, 22);

    printf("Doubly linked list after removing duplicates of 22:\n");
    printList(N1);

    return 0;
}
