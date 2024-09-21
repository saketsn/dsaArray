#include <stdio.h>
#include <stdlib.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int indexIsert(int arr[], int size, int capacity, int element, int index)
{
    if (index >= size)
    {
        return -1;
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        return 0;
    }
}

int indexDelete(int arr[], int size, int capacity, int element)
{   
    int index;
    for(int i= 0; i<= size; i++)
    {
        if(arr[i] == element)
        {
            index = i;
            break;
        }
    }
    if (index >= size)
    {
        return -1;
    }
    else
    {
        for (int i = index ; i < size; i++)
        {
            arr[i] = arr[i +1];
        }
        return 0;
    }
}

int main()
{
    int arr[100] = {1, 2, 6, 78};
    int capacity = 100;
    int size = 4, element = 1000, index = 2;
    display(arr, size);
    int result = indexIsert(arr, size, capacity, element, index);
    if (result == 0)
    {
        size += 1;
        arr[index] = element;
        display(arr, size);
    }
    else
    {
        printf("Intersion failed\n");
    }
    
    indexDelete(arr, size, capacity, element);
    size -= 1;
    display(arr, size);
    return 0;
}