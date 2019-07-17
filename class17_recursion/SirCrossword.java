import java.util.*;

public class SirCrossword {

	static boolean cpwh(char[][] arr, int i, int j, String s) {
		if (j + s.length() > arr[0].length) {
			return false;
		}

		for (int ind = 0; ind < s.length(); ind++) {
			if (arr[i][ind + j] != s.charAt(ind) && arr[i][ind + j] != '#') {
				return false;
			}
		}

		if (j + s.length() < arr[0].length && arr[i][j + s.length()] != '*') {
			return false;
		}

		return true;
	}

	static boolean cpwv(char[][] arr, int i, int j, String s) {
		if (i + s.length() > arr.length) {
			return false;
		}

		for (int ind = 0; ind < s.length(); ind++) {
			if (arr[i + ind][j] != s.charAt(ind) && arr[i + ind][j] != '#') {
				return false;
			}
		}

		if (i + s.length() < arr.length && arr[i + s.length()][j] != '*') {
			return false;
		}

		return true;
	}

	static boolean[] pwh(char[][] arr, String word, int i, int j) {
		boolean[] dipwh = new boolean[word.length()];
		for(int ind = 0; ind < word.length(); ind++) {
			if (arr[i][j + ind] == '#') {
				arr[i][j + ind] = word.charAt(ind);
				dipwh[ind] = true;
			}
		}
		return dipwh;
	}

	static boolean[] pwv(char[][] arr, String word, int i, int j) {
		boolean[] dipwh = new boolean[word.length()];
		for (int ind = 0; ind < word.length(); ind++) {
			if (arr[i + ind][j] == '#') {
				arr[i + ind][j] = word.charAt(ind);
				dipwh[ind] = true;
			}
		}
		return dipwh;
	}

	static void uwh(char[][] arr, String word, int i, int j, boolean[] dipwh) {
		for(int ind = 0; ind < word.length(); ind++) {
			if (dipwh[ind]) {
				arr[i][j + ind] = '#';
			}
		}
	}

	static void uwv(char[][] arr, String word, int i, int j, boolean[] dipwh) {
		for (int ind = 0; ind < word.length(); ind++) {
			if (dipwh[ind]) {
				arr[i + ind][j] = '#';
			}
		}
	}

	static void crossword(char[][] arr, ArrayList<String> words, int ind) {
		if (ind == words.size()) {
			for(char[] row: arr) {
				for(char ele: row) {
					System.out.print(ele + " ");
				}
				System.out.println();
			}
			return;
		}

		String word = words.get(ind);
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				boolean cpwh = cpwh(arr, i, j, word);
				boolean cpwv = cpwv(arr, i, j, word);
				if (cpwh) {
					boolean[] dipwh = pwh(arr, word, i, j);
					crossword(arr, words, ind + 1);
					uwh(arr, word, i, j, dipwh);
				}
				if (cpwv) {
					boolean[] dipwh = pwv(arr, word, i, j);
					crossword(arr, words, ind + 1);
					uwv(arr, word, i, j, dipwh);
				}
			}
		}
	}

	public static void main(String[] args) {
		char[][] grid = { "*#********".toCharArray(), "*#********".toCharArray(), "*#****#***".toCharArray(),
				"*##***##**".toCharArray(), "*#****#***".toCharArray(), "*#****#***".toCharArray(),
				"*#****#***".toCharArray(), "*#*######*".toCharArray(), "*#********".toCharArray(),
				"***#######".toCharArray() };

		ArrayList<String> words = new ArrayList<>();
		words.add("JHARKHAND");
		words.add("PUNJAB");
		words.add("MIZORAM");
		words.add("MUMBAI");
		words.add("RO");

		crossword(grid, words, 0);
	}
}