// Bubble Sort .......

#include<stdio.h>
#include<stdlib.h>

void printArray(int *A , int n)
{
     for(int i = 0; i<n ; i++)
     {
        printf("%d\t", A[i]);
     }

     printf("\n");
}

void bubblesort(int *A , int n)
{
    int temp;
    for(int i = 0; i < n; i++)  // for number of passes
    {
        for(int j = 0; j < n-1-i; j++) // for comparison in each pass 
        {
            
            if(A[j] > A[j + 1])
            {
             temp = A[j];
             A[j] = A[j + 1];
             A[j + 1] = temp;
            }
        }
    }
}

int main()
{

int A[] = { 12 , 54, 65, 7, 23, 9};
int n = 6;
printArray(A , n);

bubblesort(A , n);

printArray(A , n);



return 0;
}

