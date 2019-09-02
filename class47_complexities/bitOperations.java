import java.util.*;

public class bitOperations {
    static void setABit(int x, int k) {
        System.out.println("Number is \t" + Integer.toBinaryString(x));
        System.out.println("Mask is \t" + Integer.toBinaryString(1 << k));
        System.out.println("Result is\t" + Integer.toBinaryString(x | 1 << k));
        System.out.println();
    }

    static void unsetABit(int x, int k) {
        int y = ~(1 << k);
        System.out.println("Number is \t" + Integer.toBinaryString(x));
        System.out.println("Mask is \t" + Integer.toBinaryString(y));
        System.out.println("Result is\t" + Integer.toBinaryString(x & y));
        System.out.println();
    }

    static void toggleBit(int x, int k) {
        System.out.println("Number is \t" + Integer.toBinaryString(x));
        System.out.println("Mask is \t" + Integer.toBinaryString(1 << k));
        System.out.println("Result is\t" + Integer.toBinaryString(x ^ 1 << k));
        System.out.println();
    }
    public static void main(String[] args) {
        setABit(57, 1);
        unsetABit(57, 1);
        toggleBit(57, 1);
    }
}