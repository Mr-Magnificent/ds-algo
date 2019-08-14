import java.util.*;

public class OptimalBST {

    static int findOptimalBSTCost(int[] frequencies) {
        int[] fpsa = new int[frequencies.length];
        fpsa[0] = frequencies[0];
        for (int i = 1; i < frequencies.length; i++) {
            fpsa[i] = frequencies[i] + fpsa[i - 1];
        }

        int[][] strg = new int[frequencies.length][frequencies.length];
        for (int g = 0; g < frequencies.length; g++) {
            for (int i = 0; i < frequencies.length - g; i++) {
                int j = i + g;
                if (g == 0) {
                    strg[i][j] = frequencies[i];
                } else if (g == 1) {
                    strg[i][j] = Math.min(strg[i][j - 1] + 2 * strg[i + 1][j], strg[i][j - 1] * 2 + strg[i + 1][j]);
                } else {
                    int min = Integer.MAX_VALUE;
                    for (int k = 0; k <= g; k++) {
                        int left = (k > 0) ? strg[i][i + k - 1] : 0;
                        int right = (k != g) ? strg[i + 1 + k][j] : 0;
                        min = Math.min(left + right, min);
                    }
                    strg[i][j] = min;

                    strg[i][j] += fpsa[j];
                    if (i > 0) {
                        strg[i][j] -= fpsa[i - 1];
                    }
                }
            }
        }
        return strg[0][strg.length - 1];

    }

    public static void main(String[] args) {
        int[] frequencies = { 2, 1, 4, 1, 1, 3, 5 };
        System.out.println(findOptimalBSTCost(frequencies));
    }
}