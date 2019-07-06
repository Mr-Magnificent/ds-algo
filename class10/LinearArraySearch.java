import java.util.*;

public class LinearArraySearch {

    static int find(int[] arr, int ind, int val) {
        if(ind == arr.length) return -1;
        if(arr[ind] == val) {
            return ind;
        } else {
            return find(arr, ind + 1, val);
        }
    }
    public static void main(String[] args) {
        int[] arr = {10,20,30,40,50,60};
        System.out.println(find(arr, 0, 20));
    }
}