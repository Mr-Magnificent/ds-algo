import java.util.*;

class Job implements Comparable<Job> {
    char name;
    int deadline;
    int profit;

    Job(char name, int deadline, int profit) {
        this.name = name;
        this.deadline = deadline;
        this.profit = profit;
    }

    @Override
    public int compareTo(Job other) {
        return (other.profit - this.profit);
    }
}

public class JobSequencing {

    static String findJobString(ArrayList<Job> jobArray, int total) {
        String sequence = "";

        boolean[] selected = new boolean[total];

        int count = 0;
        for (int i = 0; i < jobArray.size(); i++) {
            for (int j = jobArray.get(i).deadline - 1; j >= 0; j--) {
                if(!selected[j]) {
                    selected[j] = true;
                    sequence += jobArray.get(i).name + " ";
                    count++;
                    break;
                }
            }
        }
        return sequence;
    }

    public static void main(String[] args) {
        ArrayList<Job> jobArray = new ArrayList<>();
        jobArray.add(new Job('a', 4, 37));
        jobArray.add(new Job('b', 2, 64));
        jobArray.add(new Job('c', 3, 98));
        jobArray.add(new Job('d', 2, 70));
        jobArray.add(new Job('e', 4, 80));
        jobArray.add(new Job('f', 5, 40));
        jobArray.add(new Job('g', 1, 54));
        jobArray.add(new Job('h', 1, 46));
        jobArray.add(new Job('i', 2, 42));
        jobArray.add(new Job('j', 3, 89));
        jobArray.add(new Job('k', 5, 27));
        jobArray.add(new Job('l', 2, 92));
        jobArray.add(new Job('m', 3, 38));
        jobArray.add(new Job('n', 5, 77));
        jobArray.add(new Job('o', 4, 46));

        Collections.sort(jobArray);

        System.out.println(findJobString(jobArray, 5));
    }
}