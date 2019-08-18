import java.util.*;

public class requiredPlatform {

    static int FindRequiredPlatforms(int[] arrival, int[] depart) {
        int count = 0;
        int max = 0;
        int i = 0;
        int j = 0;
        while (i != arrival.length && j != depart.length) {
            if (arrival[i] < depart[j]) {
                count++;
                if (max < count) {
                    max = count;
                }
                i++;
            } else if (arrival[i] > depart[j]) {
                count--;
                j++;
            }
        }
        return max;
    }
    public static void main(String[] args) {
        int[] arrival = {900, 940, 950, 1100, 1500, 1800};
        int[] depart = {910, 1200, 1120, 1130, 1900, 2000};
        Arrays.sort(arrival);
        Arrays.sort(depart);

        System.out.println(FindRequiredPlatforms(arrival, depart));
    }
}