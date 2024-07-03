package dsaArray;

public class Array1 {
	public void printArray(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			System.out.println(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Array1 arr1 = new Array1();
		arr1.printArray(new int[] { 5, 1, 2, 9, 10 });
	}
}
