import java.util.*;

public class BoxComb {

	static void printPerm(boolean[] boxes, int co, int ci, int to, String psf) {
		if (co > to) {
			System.out.println(psf);
			return;
		}

		// node pre
		for(int i = ci; i < boxes.length; i++) {
			if (boxes[i]) continue;
			boxes[i] = true;
			printPerm(boxes, co + 1, i + 1, to,  psf + " " +  co + "b" + i);
			boxes[i] = false;
		}
		// node pro
	}

	public static void main(String[] args) {
		boolean[] boxes = new boolean[5];
		int ti = 4;
		printPerm(boxes, 1, 0,ti, "");
	}
}