import java.util.*;

public class PalindromeRecusion {

    public static boolean reverse(int[] arr, int left, int right) {
        if (left == right ) {
            return true;
        } else if (arr[left] != arr[right]) {
            return false;
        } else {
            return reverse(arr, left + 1, right - 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, 50, 10 };
        System.out.println(reverse(arr, 0, arr.length - 1));
    }
}