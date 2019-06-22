import java.util.*;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the size of array");
        int size = scan.nextInt();

        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            System.out.print("Enter the " + i + "th element ");
            arr[i] = scan.nextInt();
        }

        System.out.print("Enter the element to find ");
        int ele = scan.nextInt();

        int begin = 0, end = arr.length;
        Arrays.sort(arr);
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (arr[mid] == ele) {
                System.out.println("Element found at " + mid);
                break;
            } else if (arr[mid] > ele) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        System.out.println("Element not found");
    }
}