import java.util.*;

public class Multiply {

    public static int[] arraySum(final int[] arr1, final int[] arr2) {
        int carry = 0;
        int res[] = new int[(arr1.length > arr2.length)? arr1.length + 1: arr2.length + 1];
        int k = res.length - 1;
        int i = arr1.length - 1;
        int j = arr2.length - 1;
        while(k >= 0) {
            int val = carry;
            
            if (i >= 0) {
                val += arr1[i];
            }

            if (j >= 0) {
                val += arr2[j];
            }

            res[k] = val % 10;
            carry = val / 10;

            i--;
            j--;
            k--;
        }
        return res;
    }

    public static int[] scalarMul(final int[] arr, final int ele) {
        int carry = 0;
        int[] res = new int[arr.length + 1];
        int j = arr.length - 1;
        for(int i = res.length - 1; i >= 0; i--) {
            int val = carry;
            if (j >= 0) {
                val += arr[j] * ele;
                j--;
            }
            res[i] = val % 10;
            carry = val / 10;
        }
        return res;
    }

    public static void main(String[] args) {
        // Scanner scan = new Scanner(System.in);
        String[] num1 = args[0].split("");
        String[] num2 = args[1].split("");
        int[] n2 = Arrays.asList(num1).stream().mapToInt(Integer::parseInt).toArray();
        int[] n1 = Arrays.asList(num2).stream().mapToInt(Integer::parseInt).toArray();
        int[] res = new int[n1.length + n2.length];
        // System.out.println(args[0]);
        // for(int test : n1) System.out.print(test);	
		
        int i = n1.length - 1;

        int[] tempSum = new int[n1.length + n2.length];

        while(i >= 0) {
            int[] temp = scalarMul(n2, n1[i]);
            int[] partialMul = new int[n2.length + (n1.length - i)];

            for(int j = 0; j < temp.length; j++) partialMul[j] = temp[j];

            tempSum = arraySum(tempSum, partialMul);
            i--;
        }
        int j = tempSum.length - 1;
        int k = res.length - 1;
        while(k >= 0) {
            res[k] = tempSum[j];
            k--;
            j--;
        }
        boolean trailingZero = true;
        for(i = 0; i < res.length; i++) {
            if(res[i] == 0 && trailingZero && i == res.length - 1) {
                System.out.print(0);
                continue;
            }
            if(res[i] == 0 && trailingZero) continue;
            if (res[i] != 0 && trailingZero) trailingZero = false;
            System.out.print(res[i] + " ");
        } 
        System.out.println();
    }
}
