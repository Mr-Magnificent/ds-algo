// https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
import java.util.*;

public class Matmul {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int r1, c1, r2, c2;
        System.out.println("Enter the rows and columns of first and second matrices in order");
        r1 = scan.nextInt();
        c1 = scan.nextInt();
        r2 = scan.nextInt();
        c2 = scan.nextInt();
        int[][] arr1, arr2, arr3;
        arr1 = new int[r1][c1];
        arr2 = new int[r2][c2];
        arr3 = new int[r1][c2];

        System.out.println("Enter the first array");
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c1; j++) {
                arr1[i][j] = scan.nextInt();
            }
        }

        System.out.println("Enter the second array");
        for(int i = 0; i < r2; i++) {
            for(int j = 0; j < c2; j++) {
                arr2[i][j] = scan.nextInt();
            }
        }

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                int sum = 0;
                for(int k = 0; k < c1; k++) {
                    sum += arr1[i][k] * arr2[k][j];
                }
                arr3[i][j] = sum;
            }
        }

        System.out.println("The result array is");
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++) {
                System.out.print(arr3[i][j] + " ");
            }
            System.out.println();
        }
    }
}