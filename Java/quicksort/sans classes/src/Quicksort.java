import java.util.Random;


public class Quicksort {

    static void swap(int[] array, int start, int end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
    }

    static void quicksort(int[] array, int start, int end) {

        int firstIdx = start;
        int temp;

        while (array[firstIdx] < array[end])
            firstIdx++;
        
        int secondIdx = firstIdx + 1;


        while (secondIdx < end) {
            if (!(array[secondIdx] > array[end])) {
                swap(array, firstIdx, secondIdx);
                firstIdx++;
            }
            secondIdx++;
        }
        
        
        swap(array, firstIdx, end);


        if (start < firstIdx - 1) {
            if (start == firstIdx - 2) {
                if (array[start + 1] < array[start])
                    swap(array, start, firstIdx - 1);
            } else
                quicksort(array, start, firstIdx - 1);
        }

        if (end > firstIdx + 1) {
            if (end == firstIdx + 2) {
                if (array[end] < array[end - 1])
                    swap(array, firstIdx + 1, end);
            } else
                quicksort(array, firstIdx + 1, end);
        }
                
    }

    public static void main(String[] args) {

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
        for (int i = 1; i < arrayLength; i++) {
            System.out.print(", " + array[i]);
        }
        System.out.print("\n[Array length = " + arrayLength + "]\n");
    }
}
