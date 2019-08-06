import java.util.*;

public class CoinGame {

    static int coinGame(int[] coins) {
        int[][] strg = new int[coins.length][coins.length];

        for (int g = 0; g < strg.length; g++) {
            for (int i = 0; i < strg.length - g; i++) {
                int j = i + g;

                if (g == 0) {
                    strg[i][j] = coins[j];
                } else if (g == 1) {
                    int left = strg[i][j - 1];
                    int right = strg[i + 1][j];
                    strg[i][j] = Math.max(left, right);
                } else {
                    // The opponent will try to maximize his value
                    // so we'll try to account for that
                    // murphy's law
                    int max1 = Math.max(strg[i][j - 2], strg[i + 1][j - 1]);
                    int max2 = Math.max(strg[i + 2][j], strg[i + 1][j - 1]);

                    if (max1 > max2) {
                        strg[i][j] = max1 + coins[j];
                    } else if (max1 == max2) {
                        strg[i][j] = max1 + Math.min(coins[i], coins[j]);
                    } else {
                        strg[i][j] = max2 + coins[i];
                    }
                }
            }

            if (g != 0) {
                g++;
            }
        }

        System.out.print("    ");
        for (int i = 0; i < coins.length; i++) {
            System.out.printf("%3d", coins[i]);
        }
        System.out.println();
        System.out.println();

        for (int i = 0; i < strg.length; i++) {
            System.out.printf("%3d-", coins[i]);
            for (int j = 0; j < strg.length; j++) {
                System.out.printf("%3d", strg[i][j]);
            }
            System.out.println();
        }

        return strg[0][strg[0].length - 1];
    }

    public static void main(String[] args) {
        int[] coins = { 20, 30, 2, 2 };
        System.out.println(coinGame(coins));
    }
}