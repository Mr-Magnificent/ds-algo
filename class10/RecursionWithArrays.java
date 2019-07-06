import java.util.*;;

public class RecursionWithArrays {

    static void display(int[] arr, int ind) {
        if(ind == arr.length) {
            return;
        }
        System.out.println(arr[ind]);
        display(arr, ind + 1);
    }

    public static void main(String[] args) {
        int[] arr = {10,20,30,40,50};
        display(arr, 0);
    }
}