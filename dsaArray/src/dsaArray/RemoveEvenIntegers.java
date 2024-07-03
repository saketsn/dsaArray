package dsaArray;

import java.util.ArrayList;
import java.util.Arrays;

public class RemoveEvenIntegers {
    public static void main(String[] args) {
        // Example array
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        // Remove even integers
        int[] result = removeEvenIntegers(arr);
        
        // Print the result
        System.out.println("Array after removing even integers: " + Arrays.toString(result));
    }

    public static int[] removeEvenIntegers(int[] arr) {
        // Using an ArrayList to dynamically store odd integers
        ArrayList<Integer> oddList = new ArrayList<>();
        
        // Iterate through the array and add odd integers to the list
        for (int num : arr) {
            if (num % 2 != 0) {
                oddList.add(num);
            }
        }
        
        // Convert the ArrayList back to an array
        int[] result = new int[oddList.size()];
        for (int i = 0; i < oddList.size(); i++) {
            result[i] = oddList.get(i);
        }
        
        return result;
    }
}
