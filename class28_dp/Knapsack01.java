import java.util.*;

public class Knapsack01 {

	static int knapsack01(int[] wt, int[] prices, int bagSize) {

		int[][] strg = new int[wt.length][bagSize + 1];
		for (int i = 0; i < wt.length; i++) {
			for (int j = 1; j < strg[0].length; j++) {
				if (i == 0) {
					if (wt[0] <= j) {
						strg[0][j] = prices[0];
					}
				} else {
					strg[i][j] = strg[i - 1][j];

					if (j >= wt[i]) {
						int factor = strg[i - 1][j - wt[i]] + prices[i];
						if (strg[i][j] < factor) {
							strg[i][j] = factor;
						}
					}
				}
			}
		}

		return strg[wt.length - 1][bagSize];
	}

	public static void main(String[] args) {
		int[] wt = { 2, 5, 1, 3, 4 };
		int[] prices = { 15, 14, 10, 45, 30 };
		int bagSize = 7;
		System.out.println(knapsack01(wt, prices, bagSize));
	}
}