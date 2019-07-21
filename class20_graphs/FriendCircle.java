import java.util.*;

class Edge {
	public int nbr;

	Edge(int nbr) {
		this.nbr = nbr;
	}
}

public class FriendCircle {

	static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();

	static void addEdge(int v1, int v2) {
		graph.get(v1).add(v2);
		graph.get(v2).add(v1);
	}

	static void makeGraph(int size, ArrayList<Integer> lst1, ArrayList<Integer> lst2) {
		for (int i = 0; i < size; i++) {
			graph.add(new ArrayList<Integer>());
		}

		for (int i = 0; i < lst1.size(); i++) {
			addEdge(lst1.get(i), lst2.get(i));
		}
	}

	static int friendCircleOne(int ind, boolean[] visited) {
		ArrayDeque<Integer> q = new ArrayDeque<Integer>();
		q.add(ind);
		int count = 1;
		while (!q.isEmpty()) {
			int rem = q.removeFirst();
			if (visited[rem])
				continue;
			visited[rem] = true;
			for (int i = 0; i < graph.get(rem).size(); i++) {
				if (visited[graph.get(rem).get(i)] == true)
					continue;
				q.addLast(graph.get(rem).get(i));
				count++;
			}
		}
		return count;
	}

	static ArrayList<Integer> friendCircleList() {
		ArrayList<Integer> sol = new ArrayList<Integer>();
		boolean[] visited = new boolean[graph.size()];

		for (int i = 0; i < visited.length; i++) {
			if (visited[i])
				continue;
			int friends = friendCircleOne(i, visited);
			sol.add(friends);
		}
		return sol;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the total friends");
		int totalFriends = scan.nextInt();
		ArrayList<Integer> lst1 = new ArrayList<Integer>(Arrays.asList(1, 2, 6, 7, 1));
		ArrayList<Integer> lst2 = new ArrayList<Integer>(Arrays.asList(2, 5, 8, 8, 0));

		makeGraph(totalFriends, lst1, lst2);
		ArrayList<Integer> sol = friendCircleList();
		System.out.println(sol);
	}
}