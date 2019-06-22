import java.util.*;

public class ArraySub {
    public static void main(String[] args) {
        int[] n1 = {4,3,0,1};
        int[] n2 = {0};
        int[] res = new int[n1.length >= n2.length? n1.length: n2.length];

        int greater = greater(n1, n2);

        boolean borrow = false;
        boolean resPositive = true;

        if (greater == 1) {
            int[] temp = n1;
            n1 = n2;
            n2 = temp;
            resPositive = false;
        }

        res = result(n1, n2);

        if (!resPositive) System.out.print("- ");
        for(int p = 0; p < res.length; p++) {
            System.out.print(res[p] + " ");
        }
        System.out.println();
    }

    public static void borrow(int[] arr, int ind) {
        for(int i  = ind - 1; i >= 0; i--) {
            if(arr[i] == 0) arr[i] = 9;
            else {
                arr[i] = arr[i] - 1;
                break;
            }
        }
    }

    public static int[] result(int[] n1, int[] n2) {
        int n1Ind = n1.length - 1;
        int n2Ind = n2.length - 1;
        int[] res = new int[n1.length];
        while (n1Ind >= 0) {
            int val = n1[n1Ind];
            if (n2Ind >= 0 && n2[n2Ind] > val) {
                borrow(n1, n1Ind);
                val = (val + 10) - n2[n2Ind];
            } else if (n2Ind >= 0 && n2[n2Ind] <= val) {
                val -= n2[n2Ind];
            }
            res[n1Ind] = val;
            n1Ind--;
            n2Ind--;
        }
        return res;
    }

    public static int greater(int[] n1, int[] n2) {
        int n1Ind = n1.length - 1;
        int n2Ind = n2.length - 1;
        int greater = 0;
        while (n1Ind >= 0 && n2Ind >= 0) {
            if(n1[n1Ind] >= n2[n2Ind]) greater = 0;
            else greater = 1;
            n1Ind--;
            n2Ind--;
        }
        while(n1Ind >= 0) {
            if(n1[n1Ind] != 0) greater = 0;
            n1Ind--;
        }
        while(n2Ind >= 0) {
            if(n2[n2Ind] != 0) greater = 1;
            n2Ind--;
        }
        return greater;
    }
}