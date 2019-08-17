import java.util.*;

public class largest1square {

    public static int largestSquare(int[][] mat) {

        int[][] strg = new int[mat.length][mat[0].length];
        
        return strg[0][0];
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