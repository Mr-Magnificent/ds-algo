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
                    int min1 = Math.min(strg[i][j - 2], strg[i + 1][j - 1]);
                    int min2 = Math.min(strg[i + 2][j], strg[i + 1][j - 1]);

                    if (min1 + coins[j] < min2 + coins[i]) {
                        strg[i][j] = min2 + coins[i];
                    } else  {
                        strg[i][j] = min1 + coins[j];
                    }
                }
            }

            if (g != 0) {
                g++;
            }
        }

        for (int i = 0; i < strg.length; i++) {
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