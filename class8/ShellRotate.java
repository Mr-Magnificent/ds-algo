#

import java.util.*;

public class ShellRotate {
  public static void main(String[] args) {
    int arr[][] = {
        {1, 2, 3, 4, 5},      
        {11, 12, 13, 14, 15}, 
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35}, 
        {41, 42, 43, 44, 45},
    };

    Scanner scan = new Scanner(System.in);
    int s = scan.nextInt();
    int r = scan.nextInt();

    int mid = arr[0].length / 2 + 1;

    int temp = (mid - 1) * 8;
    int tot = (temp) ? temp : 1;

    int dir = 0;
    // 0 down
    // 1 right
    // 2 up
    // 3 left

    int limdow, limright;
    int limup, limleft;
    limdow = limright = arr.length - s;
    limup = limleft = s - 1;

    for (int i = 0; i < tot; i++) {
    }
  }
}