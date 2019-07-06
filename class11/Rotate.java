import java.util.*;

public class Rotate {
    public static void main(String[] args) {
        System.out.println((new ArrayList<>(2)));
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);
        list.add(60);
        list.add(70);
        list.add(80);
        list.add(90);
        int n = 4 % list.size();
        for (int i = 0 ; i < n; i++) {
            int val = list.remove(list.size() - 1);
            list.add(i, val);
        }
        System.out.println(list);
    }
}