#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue( struct Node* f, struct Node * r,int val){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}



int main()
{
    struct Node *f = NULL;
    struct Node *r = NULL;
    enqueue(f,r,45);
    enqueue(f,r,56);
    enqueue(f,r,467);
    enqueue(f,r,123);
    linkedListTraversal(f);





return 0;
}