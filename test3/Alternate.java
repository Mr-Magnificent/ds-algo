import java.io.*;
import java.util.*;

public class Solution {

	static void recursion(String inp, int count) {
		if (inp.length() <= 2) {
			System.out.println(count);
			return;
		}

		char check0 = inp.charAt(0);
		char check1 = inp.charAt(1);
		char check2 = inp.charAt(2);
		if (Character.isAlphabetic(check0) && Character.isAlphabetic(check1) && Character.isAlphabetic(check2)) {
			recursion(inp.substring(1), count + 1);
		} else {
			recursion(inp.substring(1), count);
		}
	}

	public static void main(String[] args) {
		/*
		 * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
		 * class should be named Solution.
		 */
		Scanner scan = new Scanner(System.in);
		String inp = scan.next();
		recursion(inp, 0);

	}
}