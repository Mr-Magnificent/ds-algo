import java.util.*;

public class Perm2 {

	public static void printComb2(int cb, int n, int bssf, int r, String asf) {
		if (bssf == r) {
			System.out.println(asf);
			return;
		}
		if (cb == n) {
			return;
		}

		printComb2(cb + 1, n, bssf + 1, r, asf + cb);
		printComb2(cb + 1, n, bssf, r, asf);
	}

	public static void main(String[] args) {
		printComb2(0, 4, 0, 2, "");
	}
}