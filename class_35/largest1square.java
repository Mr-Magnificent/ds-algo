import java.util.*;

public class largest1square {

    public static int largestSquare(int[][] mat) {
        
        int[][] strg = new int[mat.length][mat[0].length];
        for (int i = 0; i < mat.length; i++) {
            for(int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 0) {
                    strg[i][j] = 0;
                }
            }
        }


    }
    public static void main(String[] args) {
        int[][] arr = {
            {1,0,0,1,0,0,1,0},
            {1,1,1,1,1,1,1,1},
            {1,1,0,1,1,1,1,1},
            {1,0,1,1,1,1,1,0},
            {0,1,1,1,1,1,1,1},
            {1,0,1,0,1,1,0,1},
            {1,0,0,1,1,1,1,1}
        };
        
        largestSquare(arr);
    }
}