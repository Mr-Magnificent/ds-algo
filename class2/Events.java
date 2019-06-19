import java.util.*;

public class Events {
    public static void main(String[] args) {
        int e1s = 0;
        int e1e = 5;
        int e2s = 2;
        int e2e = 8;
        if (e1e < e2s || e1s > e2e) {
            System.out.println("No overlap");
        } else if ((e1s < e2s && e1e > e2e) || (e1s >= e2s && e1e <= e2e)) {
            System.out.println("Full overlap");
        } else {
            System.out.println("Partial Overlap");
        }
    }
}