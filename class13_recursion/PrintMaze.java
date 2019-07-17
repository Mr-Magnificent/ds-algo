// import java.util.*;

public class PrintMaze {
	static void printPathMaze(int srcrow, int srccol, int destrow, int destcol, String ans) {
		if (srccol == destcol && srcrow == destrow) {
			System.out.println(ans);
			return;
		}
		if (srcrow < destrow) {
			printPathMaze(srcrow + 1, srccol, destrow, destcol, ans + "L");
		}
		if (srccol < destcol) {
			printPathMaze(srcrow, srccol + 1, destrow, destcol, ans + "D");
		}
	}

	public static void main(String[] args) {
		printPathMaze(0, 0, 3, 3, "");
	}
}