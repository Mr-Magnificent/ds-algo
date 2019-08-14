import java.util.*;

class Item implements Comparable<Item> {
    int weight;
    int profit;
    double ratio;

    public Item(int weight, int profit, double ratio) {
        this.weight = weight;
        this.profit = profit;
        this.ratio = ratio;
    }

    @Override
    public int compareTo(Item other) {
        if (this.ratio > other.ratio) {
            return -1;
        } else if (this.ratio < other.ratio) {
            return 1;
        } else {
            return 0;
        }
    }
}

public class FractionalKnapsack {

    static int FindBestCost(ArrayList<Item> items, double capacity) {
        int total = 0;
        for(int i = 0; i < items.size(); i++) {
            if (items.get(i).weight < capacity) {
                total += items.get(i).profit;
                capacity -= items.get(i).weight;
            }
            else if (capacity != 0) {
                total += items.get(i).ratio * capacity;
                capacity = 0;
            } else {
                break;
            }
        }
        return total;
    }

    public static void main(String[] args) {
        ArrayList<Item> items = new ArrayList<>();
        double capacity = 50;
        items.add(new Item(10, 60, 60d / 10));
        items.add(new Item(40, 40, 40d / 40));
        items.add(new Item(20, 100, 100d / 20));
        items.add(new Item(30, 120, 120d / 30));

        Collections.sort(items);
        System.out.println(FindBestCost(items, capacity));
    }
}
