// import java.util.*;

public class PrintFrontFlip {
  static void floodFill(int arr[][], int i, int j, String ans) {
    if (i == arr.length - 1 && j == arr[0].length - 1) {
      System.out.println(ans);
      return;
    }
    if (i < 0 || i >= arr.length)
      return;
    if (j < 0 || j >= arr[0].length)
      return;
    if (arr[i][j] == 1)
      return;
    if (arr[i][j] == -1)
      return;
    arr[i][j] = -1;
    floodFill(arr, i + 1, j, ans + "D");
    floodFill(arr, i - 1, j, ans + "U");
    floodFill(arr, i, j + 1, ans + "R");
    floodFill(arr, i, j - 1, ans + "L");
    arr[i][j] = 0;
  }

  public static void main(String[] args) {
    int arr[][] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 1, 0, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
    };
    floodFill(arr, 0, 0, "");
  }
}