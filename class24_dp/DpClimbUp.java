import java.util.*;

public class DpClimbUp {

	static int dpClimbUp(int n, int[] arr,int[] qb) {
		if (n == arr.length - 1) {
			return 1;
		}

		if (qb[n] != 0) {
			return qb[n];
		}

		int sol = 0;
		for(int i = 1; i <= arr[n] && (n + i) < arr.length; i++) {
			sol += dpClimbUp(i + n, arr, qb);
		}

		qb[n] = sol;
		return sol;
	}

	public static void main(String[] args) {
		int[] arr = {4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};
		int[] qb = new int[arr.length + 1];
		// Arrays.fill(qb, -1);
		System.out.println(dpClimbUp(0, arr, qb));
	}

}