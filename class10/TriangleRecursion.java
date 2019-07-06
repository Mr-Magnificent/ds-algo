import java.util.*;

public class TriangleRecursion {
    static void stars(int n,int levelInd, int starInd, boolean star) {
        if(star && levelInd >= starInd) {
            System.out.print(" * ");
            stars(n, levelInd, starInd + 1, star);
        } else if (!star && starInd == 0 && levelInd < n) {
            stars(n, levelInd, 0, true);
            System.out.println();
            stars(n, levelInd + 1, 0, false);
        } else if (!star && levelInd == n) {
            return;
        } else if (star && levelInd < starInd) {
            return;
        }
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the levels of triangle: ");
        int n = scan.nextInt();
        stars(n, 0, 0, false);
    }
}