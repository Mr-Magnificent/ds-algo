import java.util.*;

public class Rotate90 {
    public static void main(String[] args) {
        int[][] arr ={
            {1,2,3,4},
            {11,12,13,14},
            {21,22,23,24},
            {31,32,33,34}
        };
        int r = arr.length;
        int c = arr[0].length;
        for (int i = 0; i < r; i++) {
            for(int j = i; j < c; j++) {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }

        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         System.out.print(arr[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        for(int i = 0; i < arr.length; i++) {
            int l = 0;
            r = arr[0].length - 1;
            while(l < r) {
                int temp = arr[i][l];
                arr[i][l] = arr[i][r];
                arr[i][r] = temp;
                l++;
                r--;
            }
        }
        
        r = arr.length;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}