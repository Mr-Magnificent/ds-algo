// import java.util.*;

public class KeyPad {
	static String kepd[] = { "", "abc", "def", "ghi", "jhlm", "no", "pqrs", "tu", "vwxy", "z" };

	static void printKeyPad(String q, String ans) {
		if (q.length() == 0) {
			System.out.println(ans);
			return;
		}

		int ind = q.charAt(0) - '0';
		for (int i = 0; i < kepd[ind].length(); i++) {
			printKeyPad(q.substring(1), ans + kepd[ind].charAt(i));
		}
	}

	public static void main(String[] args) {
		printKeyPad("835", "");
	}
}