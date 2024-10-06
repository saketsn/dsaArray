#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    printf("Element is:");

    do
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

int insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->next;
    ptr->data = data;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return 0;
}

int insertAtAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 111;
    head->next = second;

    second->data = 222;
    second->next = third;

    third->data = 333;
    third->next = fourth;

    fourth->data = 444;
    fourth->next = head;
    printf("Circular Linked list before insertion : \n");
    traversal(head);

    printf("Circular Linked after list before insertion : \n");
    // insertAtFirst(head, 499);
    head = insertAtNode(head, third, 234);
    traversal(head);

    return 0;
}