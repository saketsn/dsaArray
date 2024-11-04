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
    int isSorted = 0;
    for(int i = 0; i < n; i++)  // for number of passes
    {
        printf("Working on pass number %d \n", i+1);
        isSorted = 1;
        for(int j = 0; j < n-1-i; j++) // for comparison in each pass 
        {
            
            if(A[j] > A[j + 1])
            {
             temp = A[j];
             A[j] = A[j + 1];
             A[j + 1] = temp;
             isSorted =0;
            }
        }
         if(isSorted)
          {
            return ;
          }
    }
   
}

int main()
{

int A[] = { 12 , 54, 65, 7, 23, 9};
//int A[] = { 1 , 2, 3, 4, 5, 6};
int n = 6;
printArray(A , n);

bubblesort(A , n);

printArray(A , n);



return 0;
}

