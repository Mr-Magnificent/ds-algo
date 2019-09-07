import java.util.*;

public class RadixSort {

    static int[] countSortForRS(int[] arr, int div) {
        int[] fm = new int[10];
        int[] output = new int[arr.length];

        for (int x : arr) {
            x = x / div % 10;
            fm[x]++;
        }

        for (int i = 1; i < fm.length; i++) {
            fm[i] += fm[i - 1];
        }

        for (int i = arr.length - 1; i >= 0; i--) {
            int val = arr[i] / div % 10;
            fm[val]--;
            output[fm[val]] = arr[i];
        }

        return output;
    }

    static int[] radixSort(int[] arr) {
        int max = 0;
        for (int x : arr) {
            max = Math.max(x, max);
        }

        int div = 1;
        while (max / div > 0) {
            arr = countSortForRS(arr, div);
            div = div * 10;
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = { 237, 324, 5435, 213, 45, 657, 45, 8, 56, 435, 234 };
        arr = radixSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}