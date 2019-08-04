import java.util.*;

public class MaximumPalindromicCuts {

    static int maximumPalindromicCuts(String s) {
        int[][] strg = new int[s.length()][s.length()];
        for (int g = 0; g < s.length(); g++) {
            for (int i = 0; i < s.length() - g; i++) {// i will start from 0 not g
                int j = i + g;
                if (i == j) {
                    strg[i][j] = 0;
                }
                // else if (g== 1 && s.charAt(i) == s.charAt(j) && strg[i + 1][j - 1] == 0) {
                // strg[i][j] = 0;
                // }
                else if (g == 1) {
                    strg[i][j] = s.charAt(i) == s.charAt(j) ? 0 : 1;
                } else {
                    if (s.charAt(i) == s.charAt(j) && strg[i + 1][j - 1] == 0) {
                        strg[i][j] = 0;
                    } else {
                        int min = Integer.MAX_VALUE;
                        for (int t = 0; t < g; t++) {
                            int left = strg[i][i + t];
                            int down = strg[i + 1 + t][j];
                            if ((left + down) < min) {
                                min = (left + down);
                            }
                        }
                        strg[i][j] = min + 1;
                    }
                }
            }
        }

        for (int i = 0; i < strg.length; i++) {
            for (int j = 0; j < strg[0].length; j++) {
                System.out.print(strg[i][j] + " ");
            }
            System.out.println();
        }
        return strg[0][strg.length - 1];
    }

    public static void main(String[] args) {
        String s = "abccbc";
        System.out.println(maximumPalindromicCuts(s));
    }
}