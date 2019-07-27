import java.util.*;

public class DpClimbUpMinPath {

	static String dpClimbUp(int n, int[] arr,String[] qb) {
		if (n == arr.length - 1) {
			return ("" + (arr.length - 1));
		}

		if (!qb[n].equals("")) {
			return qb[n];
		}

		int solSize = Integer.MAX_VALUE;
		String sol = "";
		for(int i = 1; i <= arr[n] && (n + i) < arr.length; i++) {
			String temp = dpClimbUp(i + n, arr, qb);
			if (temp.length() < solSize) {
				sol = "" + (i + n) + temp;
				solSize = temp.length();
			}
		}

		qb[n] = sol;
		return sol;
	}

	public static void main(String[] args) {
		int[] arr = {4,2,0,0,1,1,6,3,1,0,1,2,3,1,1};
		String[] qb = new String[arr.length + 1];
		Arrays.fill(qb, "");
		long start = System.currentTimeMillis();
		System.out.println(dpClimbUp(0, arr, qb));
		long end = System.currentTimeMillis();
		System.out.println("Total time in ms " + (end - start) + " ms");
	}

}