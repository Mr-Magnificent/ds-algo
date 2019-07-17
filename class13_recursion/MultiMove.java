// import java.util.*;

public class MultiMove {
	static void printPathMaze(int srcrow, int srccol, int destrow, int destcol, String ans) {
		if (srccol == destcol && srcrow == destrow) {
			System.out.println(ans);
			return;
		}
		for (int i = srcrow + 1; i <= destrow; i++) {
			printPathMaze(i, srccol, destrow, destcol, ans + "R" + (i - srcrow));
		}
		for (int i = srccol + 1; i <= destcol; i++) {
			printPathMaze(srcrow, i, destrow, destcol, ans + "C" + (i - srccol));
		}
		int tot = ((destrow - srcrow) > (destcol - srccol)) ? (destcol - srccol) : (destrow - srcrow);
		for (int i = 1; i <= tot; i++) {
			printPathMaze(srcrow, srccol + 1, destrow, destcol, ans + "D" + i);
		}
	}

	public static void main(String[] args) {
		printPathMaze(0, 0, 3, 3, "");
	}
}