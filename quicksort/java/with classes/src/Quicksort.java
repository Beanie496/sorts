import java.util.Random;


public class Quicksort {

    public static void main(String[] args) {

        Random r = new Random();
        int arrayLength = 100000;
        int arrayRange = 1000;
        int[] array = new int[arrayLength];
        
        
        array[0] = r.nextInt(arrayRange + 1);
        System.out.print(array[0]);
        for (int i = 1; i < arrayLength; i++) {
            array[i] = r.nextInt(arrayRange + 1);
            System.out.print(", " + array[i]);
        }
        System.out.print("\nSorting array...\n");
        

        Partition.quicksort(array, 0, arrayLength - 1);


        System.out.print("\nSorted array:\n");
        System.out.print(array[0]);
        for (int i = 1; i < arrayLength; i++) {
            System.out.print(", " + array[i]);
        }
        System.out.print("\n[Array length = " + arrayLength + "]\n");
    }
}
