import java.util.*;

public class CountPalindromeSubsequence {

	static int countPalindromeSubsequence(String s) {
		int[][] strg = new int[s.length()][s.length()];

		for(int g = 0; g < s.length(); g++) {
			for (int i = 0; i < s.length() - g; i++) {
				int j = i + g;
				if (i == j) {
					strg[i][j] = 1;
				} else if (s.charAt(i) == s.charAt(j)) {
					strg[i][j] = strg[i][j - 1] + strg[i + 1][j] + 1;
				} else {
					strg[i][j] = strg[i][j - 1] + strg[i + 1][j] - strg[i + 1][j - 1];
				}
			}
		}
		return strg[0][s.length() - 1];
	}

	public static void main(String[] args) {
		String s = "abckycbc";
		System.out.println(countPalindromeSubsequence(s));
	}
}