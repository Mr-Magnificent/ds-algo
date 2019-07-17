import java.io.*;
import java.util.*;

public class Solution {
	static ArrayList<String> perm(String s, int ind, boolean[] selected) {
		if (ind == s.length()) {
			ArrayList<String> sol = new ArrayList<>();
			sol.add("");
			return sol;
		}

		boolean[] unique = new boolean[26];

		ArrayList<String> mysol = new ArrayList<>();

		for(int i = 0; i < s.length(); i++) {
			int code = (s.charAt(i) - 'a');
			if (unique[code] || selected[i]) continue;
			unique[code] = true;
			selected[i] = true;
			ArrayList<String> sol = perm(s, ind + 1, selected);
			for(String str: sol) {
				mysol.add(s.charAt(i) + str);
			}
			selected[i] = false;
		}
		return mysol;
	}

	public static void main(String[] args) {
		/*
		 * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
		 * class should be named Solution.
		 */
		Scanner scan = new Scanner(System.in);
		String inp = scan.next();
		boolean[] selected = new boolean[inp.length()];
		ArrayList<String> sol = perm(inp, 0, selected);
		System.out.println(sol.size());
		for(String s: sol) {
			System.out.println(s);
		}
	}
}