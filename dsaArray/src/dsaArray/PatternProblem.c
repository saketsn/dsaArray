#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    
    int size = n * 2 - 1;
    int a[size][size];
    
    int start = 0, end = size - 1;
    int current = n;  // Keep track of current layer value
    
    // Loop to fill layers
    while (start <= end) 
    {
        // Fill top row
        for (int i = start; i <= end; i++) 
        {
            a[start][i] = current;
            a[end][i] = current;
            a[i][start] = current;
            a[i][end] = current;
        }
        // Move to the next inner layer
        start++;
        end--;
        current--;
    }
    
    // Print the matrix
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
