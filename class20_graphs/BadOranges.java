import java.util.*;

class Coordinates {
	public int x;
	public int y;
	public int time;

	Coordinates(int x, int y) {
		this.x = x;
		this.y = y;
		this.time = 1;
	}

	Coordinates(int x, int y, int time) {
		this.x = x;
		this.y = y;
		this.time = time;
	}

	@Override
	public String toString() {
		String ans = "";
		ans += this.x + " " + this.y + " " + this.time;
		return ans;
	}
}

public class BadOranges {
	static void badOranges(char[][] box) {
		ArrayDeque<Coordinates> q = new ArrayDeque<Coordinates>();

		for (int i = 0; i < box.length; i++) {
			for (int j = 0; j < box[0].length; j++) {
				if (box[i][j] == '@') {
					Coordinates c = new Coordinates(i, j);
					q.addLast(c);
				}
			}
		}

		// System.out.println(q.toString());
		boolean[][] visisted = new boolean[box.length][box[0].length];

		while (!q.isEmpty()) {
			Coordinates rem = q.removeFirst();
			// System.out.println(rem.toString());

			if (visisted[rem.x][rem.y] == true) {
				continue;
			}
			visisted[rem.x][rem.y] = true;

			if (rem.x + 1 < box.length && box[rem.x + 1][rem.y] == 'a') {
				Coordinates badApple = new Coordinates(rem.x + 1, rem.y, rem.time + 1);
				q.addLast(badApple);
				box[rem.x + 1][rem.y] = '@';
			}
			if (rem.x > 0 && box[rem.x - 1][rem.y] == 'a') {
				Coordinates badApple = new Coordinates(rem.x - 1, rem.y, rem.time + 1);
				q.addLast(badApple);
				box[rem.x - 1][rem.y] = '@';
			}
			if (rem.y + 1 < box[0].length && box[rem.x][rem.y + 1] == 'a') {
				Coordinates badApple = new Coordinates(rem.x, rem.y + 1, rem.time + 1);
				q.addLast(badApple);
				box[rem.x][rem.y + 1] = '@';
			}
			if (rem.y > 0 && box[rem.x][rem.y - 1] == 'a') {
				Coordinates badApple = new Coordinates(rem.x, rem.y - 1, rem.time + 1);
				q.addLast(badApple);
				box[rem.x][rem.y - 1] = '@';
			}
		}
	}

	public static void main(String[] args) {
		char[][] box = { "aa####aaa".toCharArray(), "a##a##@aa".toCharArray(), "@##a##aaa".toCharArray(),
				"a##a####a".toCharArray(), "a##a##aaa".toCharArray(), "a##a##aaa".toCharArray(), };

		badOranges(box);

		for(char[] row: box) {
			for (char ele: row) {
				System.out.print(ele + " ");
			}
			System.out.println();
		}
	}
}