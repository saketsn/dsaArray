#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traversal(struct Node *N1) {
    struct Node *ptr = N1;
    while (ptr != NULL) {
        printf("<- %d ->\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isDuplicate(struct Node *N1, int data) {
    struct Node *temp = N1;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

struct Node* insertAtPosition(struct Node *N1, int data, int position) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = N1;
    ptr->data = data;

    // If inserting at the beginning (position 0)
    if (position == 0) {
        ptr->next = temp;
        ptr->prev = NULL;
        if (N1 != NULL) {
            N1->prev = ptr;
        }
        return ptr;  // The new head of the list
    }

    // Traverse to the node just before the position
    int i = 0;
    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    // Insert at position
    ptr->next = temp->next;
    ptr->prev = temp;
    if (temp->next != NULL) {  // Not the last node
        temp->next->prev = ptr;
    }
    temp->next = ptr;

    return N1;  // Return the head of the list
}

int main() {
    struct Node *N1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *N2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *N3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *N4 = (struct Node*)malloc(sizeof(struct Node));

    N1->data = 11;
    N1->next = N2;
    N1->prev = NULL;

    N2->data = 22;
    N2->next = N3;
    N2->prev = N1;

    N3->data = 33;
    N3->next = N4;
    N3->prev = N2;

    N4->data = 44;
    N4->next = NULL;
    N4->prev = N3;

    traversal(N1);

    // Insert 232 at position 3
    N1 = insertAtPosition(N1, 232, 7);
    traversal(N1);

    return 0;
}
