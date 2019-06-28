import java.util.*;

public class TwoUniq {
    public static void main(String[] args) {
        int[] arr = { 1, 1, 3, 5, 5, 3, Integer.MIN_VALUE, 23, 23, Integer.MAX_VALUE };
        // 01010 = 10
        // 10111 = 23
        // 11101 = 29

        int xor = 0;
        for (int ele : arr) {
            xor ^= ele;
        }

        // for (i = 1; i <= xor; i <<= 1) {
        //     if ((xor & i) == i)
        //         break;
        // }

        int i = (int)Math.ceil((Math.log(xor) / Math.log(2))) + 1;
        i = ((((int)Math.pow(2, i) - 1) ^ xor) + 1) & xor;

        i = i & (-i);
        System.out.println(i);

        int unique1 = 0;
        int unique2 = 0;
        for (int ele : arr) {
            if ((ele & i) == i) {
                unique1 ^= ele;
            } else {
                unique2 ^= ele;
            }
        }
        System.out.println(unique1 + " " + unique2);
    }
}