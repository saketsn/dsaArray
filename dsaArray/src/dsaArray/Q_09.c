//Q9. -- Create a Single linked list without duplication, delete a particular element in a list and display the list.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a particular element from the linked list
struct Node* deleteNode(struct Node* head, int element) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Case when the head node contains the element to be deleted
    if (temp != NULL && temp->data == element) {
        head = temp->next;  // Update head
        free(temp);  // Free the old head
        return head;
    }

    // Search for the element to be deleted and keep track of the previous node
    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    // If element was not found in the list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", element);
        return head;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free the memory of the node
    free(temp);

    return head;
}

int main() {
    // Creating the linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;

    // Display the initial linked list
    printf("The single linked list is:\n");
    displayList(head);

    // Deleting the element 22
    head = deleteNode(head, 22);
    printf("The single linked list after deleting element 22 is:\n");
    displayList(head);

    return 0;
}

