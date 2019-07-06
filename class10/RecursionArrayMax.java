import java.util.*;

public class RecursionArrayMax {

    static int max(int[] arr, int ind)  {
        if(ind == arr.length) return Integer.MIN_VALUE;
        int val = max(arr, ind + 1);
        return (val > arr[ind])? val : arr[ind];
    }
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40 ,50};
        System.out.println(max(arr, 0));
    }
}