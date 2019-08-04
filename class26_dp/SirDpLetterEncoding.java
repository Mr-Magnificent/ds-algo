import java.util.*;

public class SirDpLetterEncoding {

	static int findDpSol(int[] arr, int[] sol) {
		if (arr[0] == 0) {
			return 0;
		}

		sol[0] = 1;

		if (arr[1] != 0) {
			sol[1] = sol[0];
		}

		int num = arr[0] * 10 + arr[1];
		if (num <= 26) {
			sol[1]++;
		}

		for (int i = 0; i < )
	}
	public static void main(String[] args) {
		int[] arr = { 1, 2, 1, 3, 2, 6, 1, 2, 0, 1, 4 };
		int[] dpSol = new int[arr.length];
	}
}