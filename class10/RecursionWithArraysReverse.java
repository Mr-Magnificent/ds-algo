import java.util.*;

public class RecursionWithArraysReverse {

    static void display(int[] arr, int ind) {
        if(ind == arr.length) return;
        display(arr, ind + 1);
        System.out.println(arr[ind]);
    }
    public static void main(String[] args) {
        int[] arr = {10,20,30,40,50};
        display(arr, 0);
    }
}