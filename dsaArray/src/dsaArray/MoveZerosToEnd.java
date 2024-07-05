package dsaArray;
public class MoveZerosToEnd {
    public static void main(String[] args) {
        int[] arr = {0, 1, 0, 3, 12};
        
        System.out.println("Original Array:");
        printArray(arr);
        
        moveZerosToEnd(arr);
        
        System.out.println("Array after moving zeros to the end:");
        printArray(arr);
    }

    public static void moveZerosToEnd(int[] arr) {
        int nonZeroIndex = 0; // Index to place the next non-zero element

        // Loop through the array
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex] = arr[i];
                nonZeroIndex++;
            }
        }

        // Fill the remaining positions with zeros
        while (nonZeroIndex < arr.length) {
            arr[nonZeroIndex] = 0;
            nonZeroIndex++;
        }
    }

    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
