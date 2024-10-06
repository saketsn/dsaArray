#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{

    int size;
    int top;
    char *arr;
};
char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

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
char push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack is overflower !, %d value cannot be push .\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is underflowed! cannot pop from the stack.\n");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int match(char a,char b){
    if(a== '(' && b== ')'){
        return 1;
    }
    if(a== '{' && b== '}')
    {
        return 1;
    }
    if(a== '[' && b== ']')
    {
        return 1;
    }
    return 0;
}
int parenthesisMatch(char *exp)
{
    int length = strlen(exp);
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }
}
// Function to check if parentheses in the expression are balanced
int MultiparenthesisMatch(char *exp) {
    int length = strlen(exp);
    
    // Create a stack to hold parentheses
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    
    char popped_ch;

    // Traverse through the expression
    for (int i = 0; exp[i] != '\0'; i++) {
        // If an opening parenthesis is found, push it onto the stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(sp, exp[i]);
        }
        // If a closing parenthesis is found
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            // If stack is empty, return unbalanced
            if (isEmpty(sp)) {
                return 0;
            } else {
                // Pop the last opening parenthesis and check for matching
                popped_ch = pop(sp);
                if (!match(popped_ch, exp[i])) {
                    return 0;
                }
            }
        }
    }
}

int main()
{
    char *exp = "((8+5)+(6-5))";
    
    if (MultiparenthesisMatch(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}