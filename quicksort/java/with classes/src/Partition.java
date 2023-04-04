public class Partition {

    public static void quicksort(int[] array, int start, int end) {

        int firstIdx = start;
        int temp;

        while (array[firstIdx] < array[end])
            firstIdx++;
        
        int secondIdx = firstIdx + 1;


        while (secondIdx < end) {
            if (!(array[secondIdx] > array[end])) {
                Swap.swap(array, firstIdx, secondIdx);
                firstIdx++;
            }
            secondIdx++;
        }
        
        
        Swap.swap(array, firstIdx, end);


        if (start < firstIdx - 1) {
            if (start == firstIdx - 2) {
                if (array[start + 1] < array[start]) {
                    Swap.swap(array, start, firstIdx - 1);
                }
            } else
                quicksort(array, start, firstIdx - 1);
        }

        if (end > firstIdx + 1) {
            if (end == firstIdx + 2) {
                if (array[end] < array[end - 1]) {
                    Swap.swap(array, firstIdx + 1, end);
                }
            } else
                quicksort(array, firstIdx + 1, end);
        }
                
    }
}
