import java.util.*;

public class SirArraySum {
    public static void main(String[] args) {
        int[] n1 = {1,1,1,1};
        int[] n2 = {9,9,9,9};
        int[] sum = new int[n1.length >= n2.length? n1.length + 1: n2.length + 1];

        boolean carry = false;
        int i = n1.length - 1;
        int j = n2.length - 1;
        int k = sum.length - 1;
        while(k >= 0) {
            int val = 0;
            if(carry) val = 1;

            if (i >= 0) {
                val += n1[i];
            }

            if (j >= 0) {
                val += n2[j];
            }

            int digit = val % 10;
            if(val / 10 == 1) carry = true;
            else carry = false;

            sum[k] = digit;
            i--;
            j--;
            k--;
        }
        for(int p = 0; p < sum.length; p++) {
            System.out.print(sum[p]);
        }
        System.out.println();
    }
}