import java.util.*;

public class dpLetterEncoding {

	static void findDpSol(int[] arr, int[] sol) {
		sol[0] = 1;
		for (int i = 1; i < sol.length; i++) {
			if (arr[i] == 0 && (arr[i] + arr[i - 1] * 10) <= 26 && i > 1) {
				sol[i] = sol[i - 2];
			} else if (arr[i] == 0 && (arr[i] + arr[i - 1] * 10) > 26) {
				return;
			} else if ((arr[i] + arr[i - 1] * 10) <= 26 && (arr[i] + arr[i - 1] * 10) > 9 && i > 1) {
				sol[i] = sol[i - 1] + sol[i - 2];
			} else if ((arr[i] + arr[i - 1] * 10) <= 9) {
				sol[i] = sol[i - 1];
			} else if ((arr[i] + arr[i - 1] * 10) > 26) {
				sol[i] = sol[i - 1];
			} else {
				sol[i] = sol[i - 1] + 1;
			}
		}
	}

	public static void main(String[] args) {
		int[] arr = { 1, 1, 3, 0, 2 };
		int[] dpSol = new int[arr.length];
		findDpSol(arr, dpSol);
		System.out.println(dpSol[arr.length - 1]);
	}
}