import java.util.*;

public class Prime {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // System.out.println("Enter the times to repeat");
        int t = scan.nextInt();
        while (t > 0) {
            int n;
            int flag = 0;
            // System.out.println("Enter the number");
            n = scan.nextInt();
            if (n == 1)
                // System.out.println("Neither prime nor composite");
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    System.out.println(n + " is not Prime");
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                System.out.println(n + " is Prime");
            }
            // System.out.println();
            t--;
        }
    }
}