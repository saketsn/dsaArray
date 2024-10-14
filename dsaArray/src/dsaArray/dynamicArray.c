// Q-14 -- Create a Dynamic array and perform insert, and delete in reallocated memory size.
#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void displayArray(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the dynamic array
int* insertElement(int *arr, int *size, int element) {
    // Reallocate memory to accommodate the new element
    arr = (int*) realloc(arr, (*size + 1) * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Insert the new element at the end of the array
    arr[*size] = element;
    (*size)++; // Increment the size

    return arr;
}

// Function to delete an element from the dynamic array
int* deleteElement(int *arr, int *size, int element) {
    int index = -1;

    // Find the element to be deleted
    for (int i = 0; i < *size; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Element %d not found in the array.\n", element);
        return arr;
    }

    // Shift elements to the left to overwrite the deleted element
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Reallocate memory to shrink the array size by one
    arr = (int*) realloc(arr, (*size - 1) * sizeof(int));

    if (arr == NULL && *size - 1 > 0) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    (*size)--; // Decrement the size

    return arr;
}

int main() {
    int *arr = NULL;  // Initialize the dynamic array
    int size = 0;     // Initialize the size of the array

    // Test case 1: Insert elements into the dynamic array
    printf("Inserting elements...\n");
    arr = insertElement(arr, &size, 5);
    arr = insertElement(arr, &size, 10);
    arr = insertElement(arr, &size, 15);
    arr = insertElement(arr, &size, 20);
    
    // Display the array after insertion
    printf("Array after inserting elements:\n");
    displayArray(arr, size);

    // Test case 2: Delete an element from the dynamic array
    printf("Deleting element 10...\n");
    arr = deleteElement(arr, &size, 10);
    
    // Display the array after deletion
    printf("Array after deleting element 10:\n");
    displayArray(arr, size);

    // Test case 3: Delete an element not in the array
    printf("Attempting to delete element 100 (not in array)...\n");
    arr = deleteElement(arr, &size, 100);
    
    // Display the array after trying to delete non-existent element
    printf("Array after attempting to delete element 100:\n");
    displayArray(arr, size);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
