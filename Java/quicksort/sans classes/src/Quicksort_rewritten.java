import java.util.Random;


public class Quicksort_rewritten {

	static void swap(int[] array, int start, int end)
	{
		int temp = array[start];
		array[start] = array[end];
		array[end] = temp;
	}

	static void quicksort(int[] array, int start, int end)
	{
		if (start >= end - 1)
			return;

		int temp;
		int p1 = start;
		int p2 = p1;


		while (++p2 < end)
			if (array[p2] < array[end])
				swap(array, p1++, p2);
		
		swap(array, ++p1, end);

		quicksort(array, start, p1 - 1);
		quicksort(array, p1 + 1, end);
	}

	public static void main(String[] args)
	{
		Random r = new Random();
		int arrayLength = 1000000;
		int arrayRange = 1000;
		int[] array = new int[arrayLength];
		
		
		array[0] = r.nextInt(arrayRange + 1);
		System.out.print(array[0]);
		for (int i = 1; i < arrayLength; i++) {
			array[i] = r.nextInt(arrayRange + 1);
			System.out.print(", " + array[i]);
		}
		System.out.print("\nSorting array...\n");
		

		quicksort(array, 0, arrayLength - 1);


		System.out.print("\nSorted array:\n");
		System.out.print(array[0]);
		for (int i = 1; i < arrayLength; i++)
			System.out.print(", " + array[i]);
		System.out.print("\n[Array length = " + arrayLength + "]\n");
	}
}
