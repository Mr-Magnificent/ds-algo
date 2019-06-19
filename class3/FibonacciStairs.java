import java.util.*;

public class FibonacciStairs {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int first = 0;
        int second = 1;
        int end = 1;
        int adder = 2;
        for(int i = 0; i < n; i++) {
            if (i == end) {
                System.out.println();
                end += adder;
                adder++;
            }
            System.out.print(first + " ");
            int temp = first + second;
            first = second;
            second = temp;
        }
        System.out.println();
    }
}