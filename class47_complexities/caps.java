import java.util.*;

public class caps {

    static int count = 0;

    static int cap(ArrayList<ArrayList<Integer>> arr, int person, int taken, int[] strg) {
        if (person == 4) {
            return 1;
        }

        if (strg[taken] != 0) {
            return strg[taken];
        }

        count++;

        int val = 0;
        for (int i = 0; i < arr.get(person).size(); i++) {
            int mask = (1 << arr.get(person).get(i));
            // System.out.println(mask +  " " + taken);
            if ((taken & mask) != 0) {
                continue;
            }
            taken = (taken | mask);
            val += cap(arr, person + 1, taken, strg);
            mask = ~mask;
            taken = taken & mask;
        }

        strg[taken] = val;
        return val;
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> cps = new ArrayList<>();
        cps.add(new ArrayList<Integer>(Arrays.asList(0, 2, 4)));
        cps.add(new ArrayList<Integer>(Arrays.asList(0, 1, 2, 3)));
        cps.add(new ArrayList<Integer>(Arrays.asList(1, 2, 3)));
        cps.add(new ArrayList<Integer>(Arrays.asList(0, 4)));

        int[] strg = new int[32];
        System.out.println(cap(cps, 0, 0, strg));
        System.out.println(count);
    }
}