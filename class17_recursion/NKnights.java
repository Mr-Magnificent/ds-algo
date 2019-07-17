import java.util.*;

public class NKnights {
	static int count = 0;

	static boolean isSafe(boolean[][] board, int i, int j) {
		if (i < board.length - 2 && j > 0 && board[i + 2][j - 1] == true) {
			return false;
		} else if (i < board.length - 2 && j < board.length - 1 && board[i + 2][j + 1] == true) {
			return false;
		} else if (i > 1 && j < board.length - 1 && board[i - 2][j + 1] == true) {
			return false;
		} else if (i > 1 && j > 0 && board[i - 2][j - 1] == true) {
			return false;
		} else if (i > 0 && j < board.length - 2 && board[i - 1][j + 2] == true) {
			return false;
		} else if (i > 0 && j > 1 && board[i - 1][j - 2] == true) {
			return false;
		} else if (i < board.length - 1 && j < board.length - 2 && board[i + 1][j + 2] == true) {
			return false;
		} else if (i < board.length - 1 && j > 1 && board[i + 1][j - 2] == true) {
			return false;
		}
		return true;
	}

	static void nKnights(boolean[][] board, int knights, int i, int j) {
		if (j >= board.length || i == board.length) {
			return;
		} else if (knights == board.length) {
			for (boolean[] row : board) {
				for (boolean ele : row) {
					if (ele)
					System.out.print(1 + " ");
					else
					System.out.print(0 + " ");
				}
				System.out.println();
			}
			System.out.println();
			count++;
			return;
		} else if (j == board[0].length - 1) {
			if (isSafe(board, i, j)) {
				board[i][j] = true;
				nKnights(board, knights + 1, i + 1, 0);
				board[i][j] = false;
			}
			nKnights(board, knights, i + 1, 0);
		} else {
			if (isSafe(board, i, j)) {
				board[i][j] = true;
				nKnights(board, knights + 1, i, j + 1);
				board[i][j] = false;
			}
			nKnights(board, knights, i, j + 1);
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();
		boolean[][] board = new boolean[size][size];
		nKnights(board, 0, 0, 0);
		System.out.println(count);
	}
}