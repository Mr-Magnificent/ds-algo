import java.io.*;
import java.util.*;

public class Test {

	static ArrayList<String> recur(int[] arr, int ind, int total, int target) {
		if (total + arr[arr.length - 1] == target && ind == arr.length - 1) {
			ArrayList<String> sol = new ArrayList<>();
			sol.add(arr[arr.length - 1] + "");
			sol.add("");
			return sol;
		} else if (total == target && ind == arr.length - 1) {
			ArrayList<String> sol = new ArrayList<>();
			sol.add("");
			return sol;
		}

		ArrayList<String> mySol = new ArrayList<>();
		for(int i = ind + 1; i < arr.length; i++) {
			ArrayList<String> sol = recur(arr, ind, total + arr[ind], target);
			for(String ans: sol) {
				mySol.add(arr[ind] + " " + ans);
				if (arr[ind] == 0) {
					mySol.add(ans);
				}
			}
		}
		return mySol;
	}

	public static void main(String[] args) {
		/*
		 * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
		 * class should be named Solution.
		 */
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = scan.nextInt();
		}
		int target = scan.nextInt();
		ArrayList<String> ans = recur(arr, 0, 0, target);
		System.out.println(ans.toString());
	}
}
