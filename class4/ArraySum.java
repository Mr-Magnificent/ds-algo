import java.util.*;

public class ArraySum {
    public static void main(String[] args) {
        int[] n1 = {1,1,1,1};
        int[] n2 = {9,9,9,9};
        int[] sum = new int[n1.length >= n2.length? n1.length + 1: n2.length + 1];

        boolean carry = false;
        int i, j, k;
        for (i = n1.length - 1, j = n2.length - 1, k = sum.length - 1; i >= 0 && j >=0; i--, j--, k--) {
            if (carry) {
                int temp = n1[i] + n2[j] + 1;
                if (temp / 10 != 0) {
                    carry = true;
                    sum[k] = temp % 10;
                } else {
                    carry = false;
                    sum[k] = temp;
                }
            } else {
                int temp = n1[i] + n2[j];
                if (temp / 10 != 0) {
                    carry = true;
                    sum[k] = temp % 10;
                } else {
                    carry = false;
                    sum[k] = temp;
                }
            }
        }
        if (i > 0) {
            for (; i >= 0; i--, k--) {
                if (carry) {
                    sum[k] = n1[i] + 1;
                    carry = false;
                } else {
                    sum[k] = n1[i];
                }
            }
        }
        if (j > 0) {
            for (; j >= 0; j--, k--) {
                if (carry) {
                    sum[k] = n2[j] + 1;
                    carry = false;
                } else {
                    sum[k] = n2[j];
                }
            }
        }
        if (carry) {
            sum[0] = 1;
        } else {
            sum[0] = 0;
        }
        for(int p = 0; p < sum.length; p++) {
            System.out.print(sum[p]);
        }
        System.out.println();
    }
}