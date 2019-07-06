import java.util.*;

public class Duplicate {

    public static ArrayList<Integer> duplicate(ArrayList<Integer> list, int i) {
        if (i == list.size() - 1) {
            return list;
        }
        if(list.get(i) == list.get(i+1)) {
            list.remove(i+1);
            return duplicate(list, i);
        } else {
            return duplicate(list, i + 1);
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
        System.out.println(duplicate(list, 0));
    }
}