import java.util.*;

public class caps {

    static int cap(ArrayList<ArrayList<Integer>> arr, boolean[] capTaken, int person) {
        if (person == 4) {
            return 1;
        }
        int val = 0;
        for (int i = 0; i < arr.get(person).size(); i++) {
            if (capTaken[arr.get(person).get(i)] == true) {
                continue;
            }
            capTaken[arr.get(person).get(i)] = true;
            val += cap(arr, capTaken, person + 1);
            capTaken[arr.get(person).get(i)] = false;
        }

        return val;
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> cps = new ArrayList<>();
        cps.add(new ArrayList<Integer>(Arrays.asList(0, 2, 4)));
        cps.add(new ArrayList<Integer>(Arrays.asList(0, 1, 2, 3)));
        cps.add(new ArrayList<Integer>(Arrays.asList(1, 2, 3)));
        cps.add(new ArrayList<Integer>(Arrays.asList(0, 4)));

        boolean[] capTaken = new boolean[5];
        System.out.println(cap(cps, capTaken, 0));
    }
}