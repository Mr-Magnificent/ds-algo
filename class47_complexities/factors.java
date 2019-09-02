import java.util.*;

public class factors {

    static int[] sieveOfEros(int n) {
        int[] factors = new int[n + 1];
        boolean[] sieve = new boolean[n + 1];

        Arrays.fill(sieve, true);
        sieve[0] = sieve[1] = false;

        for (int i = 0; i <= n; i++) {
            factors[i] = i;
        }

        for (int i = 2; i * i <= n; i++) {
            if (sieve[i] == true) {
                factors[i] = i;
                
                for (int j = i * i; j <= n; j += i) {

                    if (sieve[j] == true) {
                        sieve[j] = false;
                        factors[j] = i;
                    }
                }
            }
        }
        return factors;
    }

    static void factorization(int[] factors, int val) {
        System.out.print("factors of : " + val + "\t:");
        while (val > 1) {
            System.out.print(factors[val] + " * ");
            val = val / factors[val];
        }
        System.out.println(1);
    }

    public static void main(String[] args) {
        int[] factors = sieveOfEros(1000000);
        factorization(factors, 360);
        factorization(factors, 10060);
        factorization(factors, 1000);
        factorization(factors, 11000);
    }
}