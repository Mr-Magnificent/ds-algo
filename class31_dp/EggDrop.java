import java.util.*;

public class EggDrop {

    static int eggDrop(int eggs, int floors) {
        int[][] strg = new int[eggs + 1][floors + 1];
        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                if (i == 1) {
                    strg[i][j] = j;
                } else {
                    int max = Integer.MIN_VALUE;
                    for (int k = 0; k < j; k++) {
                        int lower = strg[i][j - k - 1];
                        int upper = strg[i - 1][k];
                        int min = Math.min(lower, upper);
                        
                        max = Math.max(min, max);
                    }
                    strg[i][j] = max + 1;
                }
            }
        }
        
        return strg[strg.length - 1][strg[0].length - 1];
    }

    public static void main(String[] args) {
        int eggs = 2;
        int floors = 10;
        System.out.println(eggDrop(eggs, floors));
    }
}