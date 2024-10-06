#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is Empty.\n");
        return 1;
    }
    else
    {
        printf("Stack is not Empty.\n");
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack is overflow.\n");
        return 1;
    }
    else
    {
        printf("Stack is not full.\n");
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow ! Cannot push %d to the stack.\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow ! Cannot pop  to the stack.\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int Peek(struct stack *ptr,int i)
{
    int arrInde = ptr->top - i + 1;
    if(arrInde <0){
        printf("Not a valid position.\n");
        return -1;
    }else{
    return ptr->arr[ptr->top-i+1];
    }
}
struct stack* printStack(struct stack *ptr)
{
     for(int j = 1; j < ptr->top + 1;j++){
        printf("the value of at index %d is %d.\n",j,Peek(ptr,j));
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("%d\n", isEmpty(sp));
    printf("%d\n", isFull(sp));

    push(sp, 56);
    push(sp, 45);
    push(sp, 57);
    push(sp, 53);
    push(sp, 12); // ----> pushed the 5 values
    push(sp, 66); // ----> cannot push as stack is overflow.

    printf("Stack before pop operation.\n",printStack(sp));

    printf("Pop value is %d from the stack.\n",pop(sp));
    printf("Pop value is %d from the stack.\n",pop(sp)); //----> Last in First Out.

    printStack(sp);

    

   
 
   
}