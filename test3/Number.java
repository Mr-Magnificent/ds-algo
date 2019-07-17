import java.io.*;
import java.util.*;

public class Solution {

	static void recursion(int i, long n, long k, int count) {
		if ((i * (n - i)) <= (n * k) && i < (n - i)) {
			recursion(i + 1, n, k, count + 2);
		} else if ((i * (n - i)) <= (n * k) && i == (n - i)) {
			System.out.println(count + 1);
		} else if (i >= (n - i)) {
			System.out.println(count);
		} else {
			System.out.println(count);
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