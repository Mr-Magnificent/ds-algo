import java.util.*;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int first = 0;
        int second = 1;
        System.out.print("Enter the number of elements ");
        int n = scan.nextInt();
        while (n != 0) {
            System.out.print(first + " ");
            int temp = first + second;
            first = second;
            second = temp;
            n--;
        }
        System.out.println();
    }

}