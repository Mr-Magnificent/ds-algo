import java.util.*;

public class Towers {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the size of arr");
        int size = scan.nextInt();
        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = scan.nextInt();
        }

        int max = arr[0];
        for (int x: arr) {
            if (x > max) max = x;
        }

        while(max != 0) {
            for (int i = 0; i < size; i++) {
                if (arr[i] >= max) {
                    System.out.print(" | ");
                } else {
                    System.out.print("   ");
                }
            }
            System.out.println();
            max--;
        }
    }
}