import java.util.*;

public class CountSort {

    static int[] countSort(int[] arr) {
        int[] fm = new int[10];
        int[] output = new int[arr.length];

        for (int x : arr) {
            fm[x]++;
        }

        for (int i = 1; i < fm.length; i++) {
            fm[i] += fm[i - 1];
        }

        for (int i = arr.length - 1; i >= 0; i--) {
            fm[arr[i]]--;
            output[fm[arr[i]]] = arr[i];
        }

        return output;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 4, 6, 4, 7, 9, 6, 5, 7, 0, 8, 0, 7, 6, 4, 4, 4, 1, 2 };
        int[] output = countSort(arr);

        System.out.println(Arrays.toString(output));
    }
}