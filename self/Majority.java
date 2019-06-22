// https://www.geeksforgeeks.org/majority-element/
import java.util.*;

public class Majority {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Map <Integer, Integer> m = new HashMap<Integer, Integer>();
        System.out.print("Enter the number of elements in array: ");
        int n = scan.nextInt();

        System.out.println("Enter the elements of the array");
        for(int i = 0; i < n;i++) {
            int temp;
            temp = scan.nextInt();
            if(m.containsKey(temp) == false) {
                m.put(temp, 1);
            } else {
                int initial = m.get(temp);
                m.put(temp, initial + 1);
            }
        }

        int count = 0, val = Integer.MIN_VALUE, ele = -1;
        for(Map.Entry<Integer, Integer> entry: m.entrySet()) {
            if (entry.getValue() > val) {
                val = entry.getValue();
                ele = entry.getKey();
                count = 1;
            } else if (entry.getValue() == val) {
                count++;
            }
        }
        if (count != 1) {
            System.out.println("No Majority Element");
        } else {
            System.out.println(ele);
        }
    }
}

