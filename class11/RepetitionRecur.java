import java.util.*;

public class RepetitionRecur {
    public static ArrayList<Integer> repetition (ArrayList<Integer> list, int ind, int k, int val) {
        if (ind == list.size()) {
            list.add(list.size(), k);
            return list;
        }
        if(list.get(ind) == val) {
            list.remove(ind);
            return repetition(list, ind, k + 1, val);
        } else {
            list.add(ind, k);
            return repetition(list, ind + 1, 0, list.get(ind + 1));
        }
    }
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(20);
        list.add(20);
        list.add(20);
        list.add(30);
        list.add(20);
        list.add(40);
        list.add(50);
        list.add(60);
        list.add(60);
        list.add(60);
        list.add(60);
        list.add(60);
        list.add(70);
        list.add(80);
        list.add(90);
        list.add(90);
        list.add(90);
        list.add(90);
        System.out.println(repetition(list, 0, 0, list.get(0)));
    }
}