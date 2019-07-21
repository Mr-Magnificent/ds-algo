import java.util.*;

public class KnightsTour {

	static int count = 0;

	static void knightsTour(boolean[][] board, int n, int i, int j, int visitedSoFar) {
		if (visitedSoFar == (n * n)) {
			count++;
			return;
		}

		if (i < board.length - 2 && j > 0 && board[i + 2][j - 1] != true) {
			board[i + 2][j - 1] = true;
			knightsTour(board, n, i + 2, j - 1, visitedSoFar + 1);
			board[i + 2][j - 1] = false;
		}
		if (i < board.length - 2 && j < board.length - 1 && board[i + 2][j + 1] != true) {
			board[i + 2][j + 1] = true;
			knightsTour(board, n, i + 2, j + 1, visitedSoFar + 1);
			board[i + 2][j + 1] = false;
		}
		if (i > 1 && j < board.length - 1 && board[i - 2][j + 1] != true) {
			board[i - 2][j + 1] = true;
			knightsTour(board, n, i - 2, j + 1, visitedSoFar + 1);
			board[i - 2][j + 1] = false;
		}
		if (i > 1 && j > 0 && board[i - 2][j - 1] != true) {
			board[i - 2][j - 1] = true;
			knightsTour(board, n, i - 2, j - 1, visitedSoFar + 1);
			board[i - 2][j - 1] = false;
		}
		if (i > 0 && j < board.length - 2 && board[i - 1][j + 2] != true) {
			board[i - 1][j + 2] = true;
			knightsTour(board, n, i - 1, j + 2, visitedSoFar + 1);
			board[i - 1][j + 2] = false;
		}
		if (i > 0 && j > 1 && board[i - 1][j - 2] != true) {
			board[i - 1][j - 2] = true;
			knightsTour(board, n, i - 1, j - 2, visitedSoFar + 1);
			board[i - 1][j - 2] = false;
		}
		if (i < board.length - 1 && j < board.length - 2 && board[i + 1][j + 2] != true) {
			board[i + 1][j + 2] = true;
			knightsTour(board, n, i + 1, j + 2, visitedSoFar + 1);
			board[i + 1][j + 2] = false;
		}
		if (i < board.length - 1 && j > 1 && board[i + 1][j - 2] != true) {
			board[i + 1][j - 2] = true;
			knightsTour(board, n, i + 1, j - 2, visitedSoFar + 1);
			board[i + 1][j - 2] = false;
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int r = scan.nextInt();
		int c = scan.nextInt();
		boolean[][] board = new boolean[n][n];

		board[r][c] = true;
		knightsTour(board, n, r, c, 1);
		System.out.println(count);
	}
}