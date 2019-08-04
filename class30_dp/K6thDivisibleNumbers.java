import java.util.*;

public class K6thDivisibleNumbers {

	static int k6thDivisibleNumbers(String s, int divisor) {
		int[][] strg = new int[s.length()][divisor];

		strg[0][0] = 1;
		strg[0][(s.charAt(0) - '0') % divisor] += 1;

		for (int i = 0; i < strg.length - 1; i++) {
			for (int j = 0; j < strg[0].length; j++) {
				strg[i + 1][j] += strg[i][j];

				int factor = j * 10 + (s.charAt(i + 1) - '0');
				strg[i + 1][factor % divisor] += strg[i][j];
			}
		}
		for (int i = 0; i < strg.length; i++) {
			for (int j = 0; j < strg[0].length; j++) {
				System.out.print(strg[i][j] + " ");
			}
			System.out.println();
		}
		return strg[strg.length - 1][0];
	}

	public static void main(String[] args) {
		int num = 6;
		String s = "235168";
		System.out.println((k6thDivisibleNumbers(s, num)));
	}
}