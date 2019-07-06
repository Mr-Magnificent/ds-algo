import java.util.*;

public class BinarySearch {
    static int binarySearch(int[] arr, int first, int last, int ele) {
        int mid = first + last;
        if (first > last) return -1;
        if(arr[mid] == ele) {
            return mid;
        } else if (arr[mid] > ele) {
            return binarySearch(arr, first, mid - 1, ele);
        } else {
            return binarySearch(arr, mid + 1, last, ele);
        }
    }
    public static void main(String[] args) {
        int arr[] = {10,20,30,40,50,60};
        System.out.println(binarySearch(arr, 0, arr.length - 1, 50));
    }
}