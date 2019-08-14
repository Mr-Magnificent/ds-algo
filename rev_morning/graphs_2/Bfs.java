import java.util.*;

class Edge {
    int v1 = 0;
    int v2 = 0;
    int weight = 0;

    public Edge(int v1, int v2, int weight) {
        this.v1 = v1;
        this.v2 = v2;
        this.weight = weight;
    }
}

class BFSPair {
    int vertex;
    int wsf;
    String psf;
    int noOfEdges;

    public BFSPair(int vertex, int wsf, String psf, int noOfEdges) {
        this.vertex = vertex;
        this.wsf = wsf;
        this.psf = psf;
        this.noOfEdges = noOfEdges;
    }
}

public class Bfs {

    static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();

    // ================ add vertex
    static void addVertex(int v1) {
        if (v1 == graph.size()) {
            graph.add(new ArrayList<Edge>());
        }
    }

    // =============== add edge
    static void addEdge(int v1, int v2, int weight) {
        if (v1 >= 0 && v2 < graph.size()) {
            graph.get(v1).add(new Edge(v1, v2, weight));
            graph.get(v2).add(new Edge(v2, v1, weight));
        }
    }

    // ================ display graph
    static void displayGraph(ArrayList<ArrayList<Edge>> graph) {
        for (int i = 0; i < graph.size(); i++) {
            System.out.print(i + " :");
            for (int j = 0; j < graph.get(i).size(); j++) {
                System.out.print(graph.get(i).get(j).v2 + "@" + graph.get(i).get(j).weight + " ");
            }
            System.out.println();
        }
    }

    // ================ BFS
    static void bfsTraversal(int src, int dest, boolean[] isVisited) {
        LinkedList<BFSPair> que = new LinkedList<>();
        que.addLast(new BFSPair(src, 0, src + "", 0));

        while (!que.isEmpty()) {
            BFSPair remNode = que.removeFirst();

            if (isVisited[remNode.vertex]) {
                System.out.println("Cycle Detected at " + remNode.vertex);
            }
            if (remNode.vertex == dest) {
                System.out.println("Destination found via " + remNode.psf);
            }

            isVisited[remNode.vertex] = true;

            System.out.println(remNode.vertex + " via " + remNode.psf);
            for (Edge e : graph.get(remNode.vertex)) {
                if (isVisited[e.v2])
                    continue;
                que.addLast(new BFSPair(e.v2, remNode.wsf + e.weight, remNode.psf + e.v2, remNode.noOfEdges + 1));
            }
        }
    }

    // =============== all Cycles
    static void allCycles() {
        boolean[] isVisited = new boolean[graph.size()];
        int components = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (isVisited[i])
                continue;
            DFSTraversal(i, -1, isVisited);
            System.out.println();
            components++;
        }
        System.out.println("Total components are: " + components);
    }

    // =================== DFS
    static void DFSTraversal(int src, int dest, boolean[] isVisited) {
        LinkedList<BFSPair> stk = new LinkedList<>();

        // boolean[] isVisited = new boolean[graph.size()];
        stk.addLast(new BFSPair(src, 0, src + "", 0));

        while (!stk.isEmpty()) {
            BFSPair remNode = stk.removeLast();

            if (isVisited[remNode.vertex]) {
                continue;
            }

            if(remNode.vertex == dest) {
                System.out.println("Destination found via: " + remNode.psf);
            }

            System.out.println(remNode.psf);
            isVisited[remNode.vertex] = true;

            for (Edge e : graph.get(remNode.vertex)) {
                if (isVisited[e.v2])
                    continue;
                stk.addLast(new BFSPair(e.v2, remNode.wsf + e.weight, remNode.psf + e.v2, remNode.noOfEdges + 1));
            }

            // isVisited[remNode.vertex] = false;
        }
    }

    public static void main(String[] args) {
        int n = 7;
        for (int i = 0; i < n; i++) {
            addVertex(i);
        }

        addEdge(0, 1, 10);
        addEdge(0, 3, 40);
        addEdge(1, 2, 10);
        addEdge(2, 3, 10);
        // addEdge(3, 4, 2);
        addEdge(4, 5, 2);
        addEdge(4, 6, 3);
        addEdge(5, 6, 8);

        // displayGraph(graph);
        // countEdge(graph);

        // removeEdge(0, 1);
        // System.out.println();
        // displayGraph(graph);

        // removeVertex(3);
        // System.out.println();
        // displayGraph(graph);
        boolean[] visited = new boolean[graph.size()];
        allCycles();
        // System.out.println(hasPath(0, 5, visited));
        // PrintAllPaths(0, 5, visited, "");
    }
}