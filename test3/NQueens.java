import java.util.*;

public class NQueens {

	static boolean isSafe(boolean[][] board, int i, int j) {
		for (int col = 0; col < board.length; col++) {
			if (board[i][col]) {
				return false;
			}
		}
		for (int row = 0; row < board.length; row++) {
			if (board[row][j]) {
				return false;
			}
		}
		int smallest = (i > j) ? j : i;
		int row = i - smallest;
		int col = j - smallest;
		while (row < board.length && col < board.length) {
			if (board[i][j]) {
				return false;
			}
			row++;
			col++;
		}

		if ((i + j) > (board.length - 1)) {
			col = board.length - 1;
			int temp = board.length - j - 1;
			row = i - temp;
			while (row != board.length) {
				if (board[row][col]) {
					return false;
				}
				row++;
				col--;
			}
		} else {
			row = 0;
			col = i + j;
			while (col >= 0) {
				if (board[row][col]) {
					return false;
				}
				row++;
				col--;
			}
		}
		return true;
	}

	static void nQueens(boolean[][] board, int i, int j) {
		if (i == board.length) {
			for (boolean[] row : board) {
				for (boolean ele : row) {
					if (ele)
						System.out.print(1 + " ");
					else
						System.out.print(0 + " ");
				}
			}
		} else if (j == board.length - 1) {

		} else {

		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int boardSize = scan.nextInt();
		boolean[][] board = new boolean[boardSize][boardSize];
		System.out.println(isSafe(board, 0, 0));
	}
}