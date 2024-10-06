#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top) {
    if (top == NULL) {
        printf("Stack is Empty.\n");
        return 1;
    } else {
        printf("Stack is not Empty.\n");
        return 0;
    }
}

int isFull() {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Stack is Full.\n");
        return 1;
    } else {
        free(n);  // free the allocated node to avoid memory leak
        return 0;
    }
}

struct Node *push(struct Node *top, int data) {
    if (isFull()) {
        printf("Stack overflow.\n");
        return top;
    } else {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;  // Return updated top
    }
}

int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack is Underflow.\n");
        return -1;  // Return -1 in case of underflow
    } else {
        struct Node *n = *top;
        int x = n->data;
        *top = (*top)->next;  // Correctly update the top pointer
        free(n);
        return x;
    }
}
int peek(struct Node * top, int pos){
    struct Node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int stackTop(struct Node* top) {
    if (top != NULL) {
        return top->data;
    } else {
        return -1;  // Return -1 if stack is empty
    }
}
int stackBottom(struct Node *top) {
    if (isEmpty(top)) {
        return -1;  // Return -1 if the stack is empty
    }
    struct Node *ptr = top;
    while (ptr->next != NULL) {
        ptr = ptr->next;  // Move to the last node
    }
    return ptr->data;  // Return the data of the last node
}


void listTraversal(struct Node *top) {
    while (top != NULL) {
        printf("Element: %d \n", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node *top = NULL;

    // Push elements to the stack
    top = push(top, 78);
    top = push(top, 56);
    top = push(top, 66);
    top = push(top, 54);
    top = push(top, 11);
    top = push(top, 5);

    // List all elements in the stack
    listTraversal(top);

    // Pop one element from the stack
    int element = pop(&top);
    printf("Popped Element is = %d\n", element);

    // List remaining elements in the stack
    listTraversal(top);

    for(int i=0; i<=4;i++)
    {
        printf("Value at position %d is : %d\n", i, peek(top,i));
    }
    printf("Element a the top of stack is = %d\n",stackTop(top));
    printf("Element a the bottom of stack is = %d\n",stackBottom(top));

    return 0;
}

/*
Algorithm for Stack Implementation Using a Linked List
Define Node Structure:

Create a structure Node with two members:
data: to store the integer value.
next: a pointer to the next node in the stack.
Check if Stack is Empty:

Define a function isEmpty(Node *top) that:
Checks if top is NULL.
If NULL, print "Stack is Empty" and return 1.
Otherwise, print "Stack is not Empty" and return 0.
Check if Stack is Full:

Define a function isFull() that:
Attempts to allocate memory for a new Node.
If allocation fails (malloc returns NULL), print "Stack is Full" and return 1.
Otherwise, free the allocated memory and return 0.
Push an Element onto the Stack:

Define a function push(Node *top, int data) that:
Calls isFull() to check if the stack is full.
If full, print "Stack overflow" and return top.
Otherwise, allocate memory for a new node.
Set the data of the new node.
Point the next of the new node to top.
Update top to the new node and return it.
Pop an Element from the Stack:

Define a function pop(Node **top) that:
Calls isEmpty(*top) to check if the stack is empty.
If empty, print "Stack is Underflow" and return -1.
Otherwise, store the top node in a temporary variable.
Retrieve the data from the top node.
Update top to the next node.
Free the memory of the temporary node.
Return the retrieved data.
Peek at a Specific Position:

Define a function peek(Node *top, int pos) that:
Initialize a pointer ptr to top.
Traverse the stack by moving ptr to next for pos-1 times.
If ptr is not NULL, return ptr->data.
If ptr is NULL, return -1 (invalid position).
Get the Top Element of the Stack:

Define a function stackTop(Node *top) that:
If top is not NULL, return top->data.
Otherwise, return -1 (stack is empty).
Get the Bottom Element of the Stack:

Define a function stackBottom(Node *top) that:
Calls isEmpty(top) to check if the stack is empty.
If empty, return -1.
Initialize a pointer ptr to top.
Traverse to the last node by moving ptr to next until ptr->next is NULL.
Return ptr->data (the bottom element).
Traverse the Stack:

Define a function listTraversal(Node *top) that:
While top is not NULL, print top->data.
Move top to next.
Main Function:

Initialize top to NULL.
Call push() to add elements to the stack (e.g., 78, 56, 66, 54, 11, 5).
Call listTraversal() to print all elements in the stack.
Call pop() to remove the top element and print it.
Call listTraversal() again to print remaining elements.
Use peek() to display values at specific positions (0 to 4).
Call stackTop() to get the top element and print it.
Call stackBottom() to get the bottom element and print it.
*/