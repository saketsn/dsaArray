#include <stdio.h>
#include <stdlib.h>
struct Circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct Circularqueue *q)
{
    if ((q->r+1)%(q->size)== q->f)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Circularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full!\n");
    }
    else
    {
        q->r = (q->r + 1)% q->size;
        q->arr[q->r] = val;
        printf("Enqueued element = %d\n",val);
    }
}
int dequeue(struct Circularqueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        q->f = (q->f+1)% q->size;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{

    struct Circularqueue q;
    q.size = 4;
    q.f = q.r = 0;
    int *arr = (int *)malloc(q.size * sizeof(int));

    if (isEmpty(&q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }

    if (isFull(&q))
    {
        printf("The queue is full.\n");
    }
    else
    {
        printf("The queue is not full.\n");
    }

    enqueue(&q, 45);
    enqueue(&q, 56);
    enqueue(&q, 66);
    enqueue(&q, 78);
    printf("Dequeue element is = %d.\n", dequeue(&q));

    printf("Dequeue element is = %d.\n", dequeue(&q));

    printf("Dequeue element is = %d.\n", dequeue(&q)); 

    if (isEmpty(&q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }

    if (isFull(&q))
    {
        printf("The queue is full.\n");
    }
    else
    {
        printf("The queue is not full.\n");
    }

    return 0;
}