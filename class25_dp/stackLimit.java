import java.util.*;

public class stackLimit {
	static void stack(int n) {
		System.out.println(n);
		stack(n + 1);
	}
	public static void main(String[] args) {
		stack(0);
	}
}