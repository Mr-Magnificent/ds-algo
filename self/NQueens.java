import java.util.*;

public class NQueens {

	static int[][] createDeepArray(int arr[][]) {
		int newArrSize = arr.length;
		int[][] newArr = new int[newArrSize][newArrSize];
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr[0].length; j++) {
				newArr[i][j] = arr[i][j];
			}
		}
		return newArr;
	}

	static void mark(int[][] arr, int m, int n, int val) {
		for (int i = 0; i < arr.length; i++) {
			arr[i][n] = val;
		}

		for(int j = 0; j < arr[0].length; j++) {
			arr[m][j] = val;
		}

		int smaller = (m > n)? n: m;
		int ind1 = m - smaller;
		int ind2 = n - smaller;
		while (ind1 < arr.length && ind2 < arr[0].length) {
			if(arr[ind1][ind2] == 2) {
				ind1++;
				ind2++;
				continue;
			}
			arr[ind1][ind2] = val;
			ind1++;
			ind2++;
		}
		if ((m + n) < arr.length) {
			ind1 = 0;
			ind2 = m + n;
		} else {
			int temp = arr[0].length - n - 1;
			ind1 = m - temp;
			ind2 = arr[0].length - 1;
		}
		// System.out.println(ind1 + " " + ind2);
		while (ind1 < arr.length && ind2 >= 0) {
			if (arr[ind1][ind2] == 2) {
				ind1++;
				ind2++;
				continue;
			}
			arr[ind1][ind2] = val;
			ind1++;
			ind2--;
		}
		arr[m][n] = 2;
	}

	static public boolean nQueen(int arr[][], int orrigArray[][], int arrrow, int presentQueen, int totalQueen) {

		if (presentQueen == totalQueen) {
			for (int[] row: arr) {
				for(int ele: row) {
					if (ele == -1) {
						System.out.print("  |");
					} else {
						System.out.print(" x|");
					}
				}
				System.out.println();
				for (int ele : row) {
					System.out.print("===");
				}
				System.out.println();
			}
			System.out.println();
			return true;
		}
		// if(arr[i][])
		for(int i = arrrow; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				if (arr[i][j] == 2 || arr[i][j] == -1) continue;
				int[][] tempArr = createDeepArray(arr);
				mark(tempArr, i, j, -1);
				boolean foundSol = nQueen(tempArr, arr, i + 1, presentQueen + 1, totalQueen);
				if (foundSol){
					arr[i][j] = 2;
					// System.out.println(i + " " + j);
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter the chessboard size: ");
		int n = scan.nextInt();
		int[][] arr = new int[n][n];
		nQueen(arr, arr, 0, 0, n);
	// 	mark(arr, 4, 4, 1);
	// 	mark(arr, 2, 3, 1);
	// 	System.out.println();
	// 	for (int[] row : arr) {
	// 		for (int ele : row) {
	// 			// if (ele == 0)
	// 			// System.out.print("x ");
	// 			// else
	// 			// System.out.print("- ");
	// 			System.out.print(ele + " ");
	// 		}
	// 		System.out.println();
	// 	}
	}
}