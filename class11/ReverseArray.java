import java.util.*;

public class ReverseArray {

    public static void reverse(int[] arr, int left, int right) {
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            reverse(arr, left + 1, right - 1);
        } else {
            return;
        }
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, 40, 50, 60 };
        reverse(arr, 0, arr.length - 1);
        for (int x : arr) {
            System.err.print(x + " ");
        }
        System.out.println();
    }
}