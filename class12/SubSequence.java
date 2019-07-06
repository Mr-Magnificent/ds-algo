import java.util.*;

import javax.print.DocFlavor.STRING;

public class SubSequence {

	static ArrayList<String> getss(String s) {
		String temp ="";
		if(s==temp) {
			ArrayList<String> res = new ArrayList<>();
			res.add("");
			return res;
		}
		char ch = s.charAt(0);
		String ros = s.substring(1, s.length());
		ArrayList<String> res = getss(ros);
		ArrayList<String> myres = new ArrayList<>();
		for(int i = 0; i < res.size(); i++) {
			myres.add('-' + res.get(i));
			myres.add(ch + res.get(i));
		}
		return myres;
	}
	public static void main(String[] args) {
		ArrayList<String> list = getss("abcd");
		String s = "";
		String sd = "";
		System.err.println(Integer.toHexString((s.hashCode())) + " " + Integer.toHexString((sd.hashCode())));
		System.out.println(list);
	}
}