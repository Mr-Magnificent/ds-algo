import java.util.*;

public class LSearchLast {

    static int lsearch(int[] arr, int ind, int val) {
        if(ind == arr.length) {
            return -1;
        }
        int temp = lsearch(arr, ind + 1, val);
        if(arr[ind] == val && temp == -1) {
            return ind;
        }
        return temp;
    }
    public static void main(String[] args) {
        int[] arr = {10,20,30,40,50};
        System.out.println(lsearch(arr, 0, 20));
    }
}