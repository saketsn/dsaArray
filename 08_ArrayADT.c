#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int use_size;
    int * ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{

    a->total_size = tSize;
    a->use_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
for(int i= 0; i< a->use_size;i++)
{
    printf("%d\n",(a->ptr[i]));
}
}

void set(struct myArray *a)
{
    int n;
for(int i= 0; i< a->use_size;i++)
{    
    
    printf("Enter the element %d\n",i);
    scanf("%d",&n);
    (a->ptr[i]) = n;
}
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10,3);
    printf("We are running set function \n");
    set(&marks);
    printf("We are running show function \n");
    show(&marks);

    


    return 0;
}
