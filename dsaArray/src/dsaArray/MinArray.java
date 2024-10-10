package dsaArray;

public class MinArray {

	public int findMinimum(int[] arr) {
		if (arr == null || arr.length == 0) {
			throw new IllegalArgumentException("Invalid input");
		}

		int min = arr[0];
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}

		return min;
	}

	public static void main(String[] args) {

		int[] arr = { 5, 6, 4, 34, 65, 1 };
		MinArray ma = new MinArray();
		System.out.println(ma.findMinimum(arr));
	}

}