import java.util.*;

public class Kruskals {
	public static class Edge {

		public int nbr;
		public int wt;
		Edge (int nbr, int wt) {
			this.nbr = nbr;
			this.wt = wt;
		}
	}

	public static class KEdge implements Comparable<KEdge> {
		public int v1;
		public int v2;
		public int wt;

		public KEdge (int v1, int v2, int wt) {
			this.v1 = v1;
			this.v2 = v2;
			this.wt = wt;
		}

		public int compareTo(KEdge other) {
			return this.wt - other.wt;
		}
	}

	static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();

	static void addEdge(ArrayList<ArrayList<Edge>> graph, int v1, int v2, int wt) {
		Edge e = new Edge(v2, wt);
		graph.get(v1).add(e);

		Edge e2 = new Edge(v1,wt);
		graph.get(v2).add(e2);
	}

	static void display(ArrayList<ArrayList<Edge>> graph) {
		for(int i = 0; i < graph.size(); i++) {
			System.out.print(i + ": ");
			for(int j = 0; j < graph.get(i).size(); j++) {
				System.out.print("[" + graph.get(i).get(j).nbr + "-" + graph.get(i).get(j).wt + "]");
			}
			System.out.println();
		}
	}

	static int find(int v1, int[] pa) {
		if (pa[v1] == v1) {
			return v1;
		} else {
			int val = find (pa[v1], pa);
			pa[v1] = val;
			return val;
		}
	}

	static void merge(int v1sl, int v2sl, int[] pa, int[] ra) {
		if (ra[v1sl] > ra[v2sl]) {
			pa[v2sl] = pa[v1sl];
		} else if (ra[v1sl] > ra[v2sl]) {
			pa[v1sl] = pa[v2sl];
		} else {
			pa[v1sl] = pa[v2sl];
			ra[v1sl]++;
		}
	}

	static void kruskals() {
		int[] pa = new int[graph.size()]; // parent array
		int[] ra = new int[graph.size()]; // rank array
		ArrayList<ArrayList<Edge>> mst = new ArrayList<>();

		for(int i = 0; i < graph.size(); i++) {
			pa[i] = i;
			ra[i] = 1;
			mst.add(new ArrayList<Edge>());
		}

		PriorityQueue<KEdge> pq = new PriorityQueue<>();
		for (int v= 0; v < graph.size(); v++) {
			for(int n = 0; n < graph.get(v).size(); n++) {
				Edge ne = graph.get(v).get(n);
				if (v < ne.nbr) {
					KEdge ke = new KEdge(v, ne.nbr, ne.wt);
					pq.add(ke);
				}
			}
		}

		while (!pq.isEmpty()) {
			KEdge rem = pq.remove();
			int v1 = rem.v1;
			int v2 = rem.v2;
			int v1sl = find(v1, pa);
			int v2sl = find(v2, pa);
			if (v1sl != v2sl) {
				merge(v1sl, v2sl, pa, ra);
				addEdge(mst, v1, v2, rem.wt);;
			}
		}
		display(mst);
	}

	public static void main(String[] args) {
		graph.add(new ArrayList<Edge>());
		graph.add(new ArrayList<Edge>());
		graph.add(new ArrayList<Edge>());
		graph.add(new ArrayList<Edge>());
		graph.add(new ArrayList<Edge>());
		graph.add(new ArrayList<Edge>());
		graph.add(new ArrayList<Edge>());

		addEdge(graph, 0, 1, 20);
		addEdge(graph, 1, 2, 10);
		addEdge(graph, 2, 3, 20);
		addEdge(graph, 0, 3, 40);
		addEdge(graph, 2, 5, 5);
		addEdge(graph, 3, 4, 2);
		addEdge(graph, 4, 5, 3);
		addEdge(graph, 5, 6, 3);
		addEdge(graph, 4, 6, 8);

		// display(graph);
		kruskals();
	}
}
