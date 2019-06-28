import java.util.*;

public class LowerDiagonal {
    public static void main(String[] args) {
        int[][] arr = {{1,2,3,4,5}, {11,12,13,14,15}, {21,22,23,24,25}};
        int r = arr.length;
        int c = arr[0].length;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(i >= j) {
                    System.out.print(arr[i][j] + " ");
                }
            }
            System.out.println();
        }
    }
}