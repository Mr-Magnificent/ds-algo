import java.util.*;

public class Crossword {

	static ArrayList<char[]> deepcopy(ArrayList<char[]> grid) {
		ArrayList<char[]> t = new ArrayList<>();
		for (char[] gridrow : grid) {
			char[] temp = gridrow.clone();
			t.add(temp);
		}
		return t;
	}

	static ArrayList<char[]> fill(ArrayList<char[]> grid, String word, final int i, final int j, final boolean dir) {
		// dir -> true = across
		// dir -> false = down
		ArrayList<char[]> copy = deepcopy(grid);
		boolean inserted = true;
		if (dir) {
			int col;
			for (col = 0; col < word.length() && (j + col) != grid.get(0).length; col++) {
				if (copy.get(i)[j + col] == '#' || copy.get(i)[j + col] == word.charAt(col)) {
					copy.get(i)[j + col] = word.charAt(col);
				} else {
					inserted = false;
					break;
				}
			}
			if (col != word.length())
				inserted = false;
			if (inserted) {
				return copy;
			} else {
				return grid;
			}
		} else {
			int row;
			for (row = 0; row < word.length() && (i + row) != grid.size(); row++) {
				if (copy.get(i + row)[j] == '#' || copy.get(i + row)[j] == word.charAt(row)) {
					copy.get(i + row)[j] = word.charAt(row);
				} else {
					inserted = false;
					break;
				}
			}
			if (row != word.length())
				inserted = false;

			if (inserted) {
				return copy;
			} else {
				return grid;
			}
		}
	}

	static void crossword(int i, int j, ArrayList<char[]> grid, ArrayList<String> words) {
		// System.out.println("hello");
		if (i == grid.size() || words.isEmpty()) {

			for (char[] s : grid) {
				for (char cha : s) {
					System.out.print(cha + " ");
				}
				System.out.println();
			}

		} else if (j == grid.get(0).length - 1) {
			// System.out.println(i + " " + j);
			if (grid.get(i)[j] == '#') {
				for (int ind = 0; ind < words.size(); ind++) {
					for (int turn = 0; turn < 2; turn++) {
						char ch = grid.get(i)[j];
						if (turn == 0)
							grid = fill(grid, words.get(ind), i, j, false);
						else
							grid = fill(grid, words.get(ind), i, j, true);

						if (grid.get(i)[j] == ch) {
							continue;
						}
						String word = words.remove(ind);
						crossword(i + 1, 0, grid, words);
						for (char[] s : grid) {
							for (char cha : s) {
								System.out.print(cha + " ");
							}
							System.out.println();
						}
						if (turn == 1) {
							for (int temp = 0; temp < word.length(); temp++) {
								if (i > 0 && grid.get(i - 1)[j + temp] != '*') {
									continue;
								}
								if (i < grid.size() - 1 && grid.get(i + 1)[j + temp] != '*') {
									continue;
								}
								grid.get(i)[j] = '#';
							}
						} else {
							for (int temp = 0; temp < word.length(); temp++) {
								if (j > 0 && grid.get(i + temp)[j - 1] != '*') {
									continue;
								}
								if (j < grid.get(0).length - 1 && grid.get(i + temp)[j + 1] != '*') {
									continue;
								}
								grid.get(i)[j] = '#';
							}
						}
						words.add(word);
						System.out.println(word);

					}
				}
			} else {
				crossword(i + 1, 0, grid, words);
			}
		} else {
			if(grid.get(i)[j] == '#') {
				for (int ind = 0; ind < words.size(); ind++) {
					for(int turn = 0; turn < 2; turn++) {
						char ch = grid.get(i)[j];
						if (turn == 0)
						grid = fill(grid, words.get(ind), i, j, false);
						else
						grid = fill(grid, words.get(ind), i, j, true);

						if (grid.get(i)[j] == ch) {
							continue;
						}
						String word = words.remove(ind);
						crossword(i, j + 1, grid, words);
						for (char[] s : grid) {
							for (char cha : s) {
								System.out.print(cha + " ");
							}
							System.out.println();
						}
						if (turn == 1) {
							for (int temp = 0; temp < word.length(); temp++) {
								if (i > 0 && grid.get(i - 1)[j + temp] != '*') {
									continue;
								}
								if (i < grid.size() - 1 && grid.get(i + 1)[j + temp] != '*') {
									continue;
								}
								grid.get(i)[j] = '#';
							}
						} else {
							for (int temp = 0; temp < word.length(); temp++) {
								if (j > 0 && grid.get(i + temp)[j - 1] != '*') {
									continue;
								}
								if (j < grid.get(0).length - 1 && grid.get(i + temp)[j + 1] != '*') {
									continue;
								}
								grid.get(i)[j] = '#';
							}
						}
						words.add(word);
						System.out.println(word);

					}
				}
			} else {
				crossword(i, j + 1, grid, words);
			}
		}
	}

	public static void main(String[] args) {
		ArrayList<char[]> grid = new ArrayList<>();
		ArrayList<String> words = new ArrayList<>();

		grid.add("*#********".toCharArray());
		grid.add("*#********".toCharArray());
		grid.add("*#****#***".toCharArray());
		grid.add("*##***##**".toCharArray());
		grid.add("*#****#***".toCharArray());
		grid.add("*#****#***".toCharArray());
		grid.add("*#****#***".toCharArray());
		grid.add("*#*######*".toCharArray());
		grid.add("*#********".toCharArray());
		grid.add("***#######".toCharArray());

		words.add("JHARKHAND");
		words.add("PUNJAB");
		words.add("MIZORAM");
		words.add("MUMBAI");

		crossword(0, 0, grid, words);
		// grid = fill(grid, "JHARKHAND", 0, 1, false);
	}
}