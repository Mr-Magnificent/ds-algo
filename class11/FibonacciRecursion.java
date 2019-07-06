import java.util.*;

public class FibonacciRecursion {
    static void fibo(int n, int cuCount, int prev, int curr) {
        if(n == cuCount) {
            return;
        }
        System.out.print(prev + " ");
        fibo(n, cuCount + 1, curr, prev + curr);
    }
    public static void main(String[] args) {
        int n = 5;
        fibo(n, 0, 0, 1);
    }
}