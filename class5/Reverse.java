import java.util.*;

public class Reverse {

    public static void swap(int[] arr, int left, int right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    public static void reverse(int[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while(left < right) {

            swap (arr, left, right);
            
            left++;
            right--;
        }
    }

    public static void print(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

    }
    public static void main(String[] args) {
        int[] arr = {10, 20 , 30 , 40, 50, 60};
        reverse(arr);
        print(arr);
        }
}