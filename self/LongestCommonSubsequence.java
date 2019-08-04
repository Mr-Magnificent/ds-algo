import java.util.*;

public class LongestCommonSubsequence {

	static int longestCommonSubsequence(String s1, String s2) {
		int[][] strg = new int[s1.length() + 1][s2.length() + 1];
		for (int i = 0; i <= s1.length(); i++) {
			strg[s1.length()][i] = 0;
		}
		for (int i = 0; i <= s2.length(); i++) {
			strg[i][s2.length()] = 0;
		}

	}
	public static void main(String[] args) {

	}
}