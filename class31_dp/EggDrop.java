import java.util.*;

public class EggDrop {

    static int eggDrop(int eggs, int floors) {
        int[][] strg = new int[eggs + 1][floors + 1];
        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                if (i == 1) {
                    strg[i][j] = j;
                } else {
                    int min = Integer.MAX_VALUE;
                    for (int k = 0; k < j; k++) {
                        int lower = strg[i][j - k - 1];
                        int upper = strg[i - 1][k];
                        int max = Math.max(lower, upper);

                        min = Math.min(min, max);
                    }
                    strg[i][j] = min + 1;
                }
            }
        }

        for (int i = 0; i < strg.length; i++) {
            for (int j = 0; j < strg[0].length; j++) {
                System.out.print(strg[i][j] + " ");
            }
            System.out.println();
        }
        
        return strg[strg.length - 1][strg[0].length - 1];
    }

    public static void main(String[] args) {
        int eggs = 2;
        int floors = 10;
        System.out.println(eggDrop(eggs, floors));
    }
}