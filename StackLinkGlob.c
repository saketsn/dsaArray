#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Global variable
struct Node *top = NULL;

int isEmpty(struct Node *tp) {
    if (tp == NULL) {
        printf("Stack is Empty.\n");
        return 1;
    } else {
        printf("Stack is not Empty.\n");
        return 0;
    }
}

int isFull(struct Node *tp) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Stack is Full.\n");
        return 1;
    } else {
        return 0;
    }
}

struct Node *push(struct Node *tp, int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isFull(n)) {
        printf("Stack overflow.\n");
        return tp;
    } else {
        n->data = data;
        n->next = tp;
        tp = n;
        return tp;
    }
}

int pop(struct Node** tp) {
    if (isEmpty(*tp)) {
        printf("Stack is Underflow.\n");
        return -1; // Return an error value in case of underflow
    } else {
        struct Node *n = *tp;
        int x = n->data;
        *tp = (*tp)->next; // Correctly update the tp pointer
        free(n);
        return x;
    }
}

void listTraversal(struct Node *tp) {
    while (tp != NULL) {
        printf("Element: %d \n", tp->data);
        tp = tp->next;
    }
    printf("\n");
}

int main() {
  
    top = push(top, 78);
    top = push(top, 56);
    top = push(top, 66);
    top = push(top, 54);
    top = push(top, 11);
    top = push(top, 5);

    listTraversal(top);

    int element = pop(&top); // Pass the address of top
    printf("Pop Element is = %d\n", element);

    listTraversal(top);

    return 0;
}
/*

*/