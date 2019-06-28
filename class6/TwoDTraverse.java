import java.util.*;

public class TwoDTraverse {
    public static void main(String[] args) {
        int [][] arr = {
            {0,0,1,0},
            {1,0,0,0},
            {0,0,0,0},
            {1,0,1,0},
        };

        int r = arr.length;
        int c = arr[0].length;
        int dir = 0;
        // 0 right
        // 1 down
        // 2 left
        // 3 up

        int cr = 0, cc = 0;
        while ((0 <= cr) && (cr < r) && (0 <= cc) && (cc < c)) {
            if(arr[cr][cc] == 0) {
                switch(dir) {
                    case 0:
                        cc++;
                        break;
                    case 1:
                        cr++;
                        break;
                    case 2:
                        cc--;
                        break;
                    case 3:
                        cr--;
                        break;
                }
            } else {
                switch(dir) {
                    case 0:
                        dir = 1;
                        cr++;
                        break;
                    case 1:
                        cc--;
                        dir = 2;
                        break;
                    case 2:
                        cr--;
                        dir = 3;
                        break;
                    case 3:
                        cc++;
                        dir = 0;
                        break;
                }
            }
        }
        if (dir == 0) System.out.println(cr + " " + (cc - 1));
        else if (dir == 1) System.out.println((cr - 1) + " " + cc);
        if (dir == 2) System.out.println(0 + " " + cc);
        if (dir == 3) System.out.println(cr + " " + 0);
    }
}