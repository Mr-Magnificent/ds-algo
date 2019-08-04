import java.util.*;

public class UnboundedKnapsack {

	static int findUnboundedKnapSack(int[] wt, int[] prices, int bagSize) {
		int[] strg = new int[bagSize + 1];

		strg[0] = 0;

		for (int i = 1; i < strg.length; i++) {
			int max = Integer.MIN_VALUE;
			for (int j = 0; j < wt.length; j ++) {
				if (wt[j] <= i) {
					max = Math.max(max, strg[i - wt[j]] + prices[j]);
				}
			}
			strg[i] = max;
		}
		return strg[strg.length - 1];
	}

	public static void main(String[] args) {
		int[] wt = { 2, 5, 1, 3, 4 };
		int[] prices = { 15, 14, 10, 45, 30 };
		int bagSize = 7;
		System.out.println(findUnboundedKnapSack(wt, prices, bagSize));
	}
}