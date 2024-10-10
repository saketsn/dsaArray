package dsaArray;

public class ArrayUnit {

	public void printArray(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public void arrayDemo() {
		int[] myArray = new int[5];
		myArray[0] = 5;
		myArray[1] = 1;
		myArray[2] = 8;
		myArray[3] = 2;
		myArray[4] = 10;
		myArray[2] = 30;
		printArray(myArray);
		System.out.println(myArray.length);
		System.out.println(myArray.length - 1);
		System.out.println(myArray[3]);

		int[] arr = { 5, 6, 7, 8 };
		printArray(arr);
		int[] sak = new int[4];
		sak[0] = 5;
		sak[1] = 5123;
		sak[2] = 5123255;
		sak[3] = 53535;
		printArray(sak);

	}

	public static void main(String[] args) {
		ArrayUnit arrUnit = new ArrayUnit();
		arrUnit.arrayDemo();
	}
}
