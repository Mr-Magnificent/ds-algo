import java.util.*;

public class DpClimbUpMin {

	static int dpClimbUp(int n, int[] arr,int[] qb) {
		if (n == arr.length - 1) {
			return 0;
		}

		if (qb[n] != 0) {
			return qb[n];
		}

		int sol = Integer.MAX_VALUE;
		for(int i = 1; i <= arr[n] && (n + i) < arr.length; i++) {
			int temp = dpClimbUp(i + n, arr, qb);
			if (temp < sol) {
				sol = ++temp;
			}
		}

		qb[n] = sol;
		return sol;
	}

	public static void main(String[] args) {
		int[] arr = {4,2,0,0,1,1,6,3,1,0,1,2,3,1,1};
		int[] qb = new int[arr.length + 1];
		long start = System.currentTimeMillis();
		System.out.println(dpClimbUp(0, arr, qb));
		long end = System.currentTimeMillis();
		System.out.println("Total time in ms " + (end - start) + " ms");
	}

}