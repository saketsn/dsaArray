//Q-01 -- Create a Single linked list without duplication and display the elements
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the element is already in the list (duplicates)
int isDuplicate(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1; // Duplicate found
        }
        temp = temp->next;
    }
    return 0; // No duplicate
}

// Function to insert a node at the end of the list if it's not a duplicate
void insert(struct Node** head, int data) {
    if (isDuplicate(*head, data)) {
        printf("%d is already in the list, skipping.\n", data);
        return;
    }

    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    int n, data;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Elements of the list:\n");
    displayList(head);
    insert(&head,22);
    return 0;
}
