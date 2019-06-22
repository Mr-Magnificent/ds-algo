import java.util.*;

public class Search {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int size = scan.nextInt();

        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            System.out.print("Enter the " + i + "th element ");
            arr[i] = scan.nextInt();
        }

        System.out.print("Enter the element to find ");
        int ele = scan.nextInt();

        for(int i = 0; i < size; i++) {
            if (arr[i] == ele) {
                System.err.println("Element found at index " + i);
                return;
            }
        }
        System.out.println("Element not found");
    }
}