import java.io.*;
import java.util.*;

public class Number {

	static void recursion(int i, long n, long k, int count) {
		if (i == n / 2) {
			if ((i * (n - i)) <= ((n * k) % Long.MAX_VALUE)) {
				if (n % 2 == 1) {
					System.out.println(count + 2);
				} else {
					System.out.println(count + 1);
				}
			} else {
				System.out.println(count);
			}
			return;
		}

		if ((i * (n - i)) <= ((n * k) % Long.MAX_VALUE) && i != (n - 1)) {
			recursion(i + 1, n, k, count + 2);
		}
	}

	public static void main(String[] args) {
		/*
		 * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
		 * class should be named Solution.
		 */
		Scanner scan = new Scanner(System.in);
		int q = scan.nextInt();
		while (q != 0) {
			long n = scan.nextLong();
			long k = scan.nextLong();
			recursion(1, n, k, 0);
			q--;
		}

	}
}