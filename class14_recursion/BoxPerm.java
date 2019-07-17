import java.util.*;

public class BoxPerm {

	static void printPerm(boolean[] boxes, int co, int to, String psf) {
		if (co > to) {
			System.out.println(psf);
			return;
		}

		for(int i = 0; i < boxes.length; i++) {
			if (boxes[i]) continue;
			boxes[i] = true;
			printPerm(boxes, co + 1, to, psf + " " +  co + "b" + i);
			boxes[i] = false;
		}
	}

	public static void main(String[] args) {
		boolean[] boxes = new boolean[5];
		int ti = 3;
		printPerm(boxes, 1, ti, "");
	}
}