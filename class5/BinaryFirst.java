import java.util.*;

public class BinaryFirst {
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
        boolean found = false;
        int begin = 0, end = arr.length - 1;
        Arrays.sort(arr);
        int pos = -1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (arr[mid] == ele) {
                // System.out.println("Element found at " + mid);
                found = true;
                pos = mid;
                end = mid - 1;
                // break;
            } else if (arr[mid] > ele) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        if (pos == -1) System.out.println("Element not found");
        else System.out.println("Element found at " + pos);

        // if(!found) System.out.println("Element not found");
    }
}