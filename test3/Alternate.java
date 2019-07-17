import java.io.*;
import java.util.*;

public class Alternate {

	static boolean check(String inp) {
		if (inp.length() < 3) {
			return false;
		} else if (inp.charAt(0) != inp.charAt(2)) {
			return false;
		} else if (!Character.isAlphabetic(inp.charAt(0))) {
			return false;
		} else if (!Character.isAlphabetic(inp.charAt(1))) {
			return false;
		}
		return true;
	}

	static int recursion(String inp) {
		// System.out.println(inp);
		if (inp.length() == 0) {
			return 0;
		}
		if(!check(inp)) {
			return recursion(inp.substring(1));
		}
		int val1 = recursion(inp.substring(1));
		int val2 = recursion(inp.substring(3));
		val1 += 1;
		val2 += 2;
		if (val1 > val2) return val1;
		else return val2;
	}

	public static void main(String[] args) {
		/*
		 * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
		 * class should be named Solution.
		 */
		Scanner scan = new Scanner(System.in);
		String inp = scan.next();
		System.out.println((recursion(inp)));

	}
}