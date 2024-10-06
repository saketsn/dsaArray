#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *array;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 2;
    s->top = -1;
    s->array = (int *)malloc(s->size * sizeof(int));

    s->array[0] = 23;
    s->top++;
    s->array[1] = 25;
    s->top++;
    s->array[2] = 27;
    s->top++;
   
    

    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }
    if (isFull(s))
    {
        printf("Stack is full.\n");
    }
    else
    {
        printf("Stack is not full.\n");
    }


    return 0;
}