import java.util.*;

public class LongestPalindromicSubsequence {
	static int longestPalindromicSubsequence(String s) {
		int[][] strg = new int[s.length()][s.length()];
		for (int j = 0; j < s.length(); j++) {
			for (int i = 0; i < s.length(); i++) {
				if(i>j){
					continue;
				}
				if (i == j) {
					strg[i][j] = 1;
				} else if (i == s.length() - 1 || j == 0) {
					continue;
				} else if (s.charAt(i) == s.charAt(j)) {
					strg[i][j] = 2 + strg[i + 1][j - 1];
				} else {
					strg[i][j] = Math.max(strg[i][j - 1], strg[i + 1][j]);
				}
			}
		}
		for (int i = 0; i < strg.length; i++) {
			for (int j = 0; j < strg.length; j++) {
				System.out.print(strg[i][j] + " ");
			}
			System.out.println();
		}
		return strg[strg.length - 1][strg.length - 1];
	}

	public static void main(String[] args) {
		String s = "abckycbc";
		System.out.println(longestPalindromicSubsequence(s));
	}
}