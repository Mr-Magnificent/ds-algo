import java.util.*;

public class Diamond {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int nspaces = n/2;
        int nstars = 1;
        
        int sec = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nspaces; j++) {
                System.out.print(" # ");
            }

            for (int j = 0, secInner = sec; j < nstars; j++) {
                System.out.print(" " + (secInner) + " ");
                if (j < nstars/2) {
                    secInner++;
                } else {
                    secInner--;
                }
            }
            
            for (int j = 0; j < nspaces; j++) {
                System.out.print(" # ");
            }
            if (i < n/2) {
                nspaces--;
                nstars += 2;
                sec++;
            } else {
                nspaces++;
                nstars -= 2;
                sec--;
            }
            System.out.println();
        }
    }
}