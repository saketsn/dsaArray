#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traveral(struct Node *head)
{
    struct Node *ptr = head;
    printf("Element is:");
    
    
    do{
        printf(" %d ->",ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
    printf("\n");
}

int main()
{
        struct Node * head = (struct Node*)malloc(sizeof(struct Node));
        struct Node * second = (struct Node*)malloc(sizeof(struct Node));
        struct Node * third = (struct Node*)malloc(sizeof(struct Node));
        struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));

        head->data = 111;
        head->next = second;

        second->data = 222;
        second->next = third;

        third->data  = 333;
        third->next  = fourth;

        fourth->data = 444;
        fourth->next = head;

        traveral(head);


        



    return 0;
}