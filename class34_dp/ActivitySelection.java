import java.util.*;

 class Interval implements Comparable<Object> {
    int start;
    int end;

    Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public int compareTo(Object other) {
        
        return this.start - ((Interval)other).start;
    }

    public static void activitySelection(int[] starts, int[] ends) {
        Interval[] intvs = new Interval[starts.length];
        for (int i = 0; i < starts.length; i++) {
            intvs[i] = new Interval(starts[i], ends[i]);
        }

        Arrays.sort(intvs);

        int count = 1;
        int lai = 0;
        for (int i = 1; i < intvs.length; i++) {
            if (intvs[i].start > intvs[lai].end) {
                count++;
                lai = i;
            }
        }
        System.out.println(count);
    }
}

public class ActivitySelection {
    public static void main(String[] args) {
        int[] starts = {12, 2, 6, 7, 9, 3, 3};
        int[] ends = {14, 5, 8, 10, 10, 4, 3};
        Interval.activitySelection(starts, ends);
    }
}