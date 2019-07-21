import java.util.*;

class Element implements Comparable {
	public string s;
	int count;

	Element(String s) {
		this.s = s;
	}

	@Override
	public String toString() {
		return this.s + " " + this.count;
	}
}

public class StringSubs {

	static HashSet<Character> getUniqChaSet(ArrayList<String> words) {
		HashSet<Character> set = new HashSet<Character>();
		for(String s: words) {
			char[] arr = s.toCharArray();
			for(int i = 0; i < arr.length; i++) {
				if (!set.contains(arr[i])) {
					set.add(arr[i]);
				}
			}
		}
		return set;
	}

	static int minChanges(String source, String dest , HashSet<Character> uniqCharacters) {
		int count = 0;
		ArrayDeque<String> q = new ArrayDeque<String>();
		q.addLast(source);
		while (!q.isEmpty()) {
			Element rem = q.removeFirst();
			if (rem.contains(dest)) {
				return count;
			}

		}
		return count;
	}
	public static void main(String[] args) {
		ArrayList<String> words = new ArrayList<String>();
		words.add("BCCI");
		words.add("AICC");
		words.add("ICC");
		words.add("CCI");
		words.add("MCC");
		words.add("MCA");
		words.add("ACC");
		HashSet<Character> uniqCharacters = getUniqChaSet(words);
		// System.out.println(uniqCharacters);
	}
}