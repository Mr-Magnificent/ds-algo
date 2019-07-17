// import java.util.*;

public class RecursiveSubStrings {

	static void recSubStr(String s, String ans) {
		if (s.length() == 0) {
			System.out.println(ans);
			return;
		}

		String temp = s.substring(1);
		recSubStr(temp, ans + s.charAt(0));
		recSubStr(temp, ans + "-");
	}

	public static void main(String[] args) {
		recSubStr("abc", "");
	}
}
