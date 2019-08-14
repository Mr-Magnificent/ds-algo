import java.util.*;

public class MatrixChainMultiplication {

    static int matrixChainMultiplication(int[] dims) {
        int[][] strg = new int[dims.length - 1][dims.length - 1];

        for (int g = 0; g < strg.length; g++) {
            for (int i = 0; i < strg[0].length - g; i++) {

                int j = i + g;

                if (g == 0) {
                    strg[i][j] = 0;

                } else if (g == 1) {
                    strg[i][j] = dims[i] * dims[j] * dims[j + 1];

                } else {
                    int min = Integer.MAX_VALUE;

                    for (int k = 0; k < g; k++) {
                        int left = strg[i][i + k];
                        int right = strg[i + k + 1][j];
                        if ((left + right) < min) {
                            min = left + right;
                            strg[i][j] = min + dims[i] * dims[k + 1] * dims[j + 1];
                        }
                    }
                }
            }
        }
        return strg[0][strg.length - 1];
    }

    public static void main(String[] args) {
        int[] dims = new int[] { 10, 20, 30, 40, 50, 60 };
        System.out.println(matrixChainMultiplication(dims));
    }
}
