import java.util.*;

public class TotOccurance {

    public static int[] rec(int[] arr, int ind, int ele, int count) {
        if(ind == arr.length) {
            return new int[count];
        }
        int[] finl;
        if (arr[ind] == ele) {
            finl = rec(arr, ind + 1, ele, count + 1);
            finl[count] = ind;
            return finl;
        }
        return rec(arr, ind + 1, ele, count);
    }
    public static void main(String[] args) {
        int[] arr = {10,20,30,40,10,01,10,10};
        int[] val = rec(arr, 0, 10, 0);
        for(int x: val) {
            System.out.println(x);
        }
    }
}