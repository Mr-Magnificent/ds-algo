import java.util.*;

public class Comb2 {
	static void comb2(int cb, int n, int bssf, int r, String ans, boolean[] items) {


		comb2(cb + 1, n, bssf + 1, r, ans, items);
		for (int i = 0; i < items.length; i++) {
			if (items[i]) continue;
			items[i] = true;
			comb2(cb + 1, n, bssf + 1, r, ans + i + "" + cb + " ", items);
			items[i] = false;
		}
	}
	public static void main(String[] args) {

	}
}