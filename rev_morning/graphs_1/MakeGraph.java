import java.util.*;

class Edge {
    int v1 = 0;
    int v2 = 0;
    int weight = 0;

    public Edge (int v1, int v2, int weight) {
        this.v1 = v1;
        this.v2 = v2;
        this.weight = weight;
    }
}

public class MakeGraph {

    // =============== graph
    static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();

    // ================ add vertex
    static void addVertex (int v1) {
        if (v1 == graph.size()) {
            graph.add(new ArrayList<Edge>());
        }
    }

    // =============== get index 
    static int getIdx (int v1, int v2) {
        for (int i = 0; i < graph.get(v1).size(); i++) {
            Edge e = graph.get(v1).get(i);
            if (e.v2 == v2) {
                return i;
            }
        }
        return -1;
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

    static void countEdge(ArrayList<ArrayList<Edge>> graph) {
        int count = 0;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.get(i).size(); j++) {
                if (graph.get(i).get(j).v2 > i) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }

    // ============== remove edge
    static void removeEdge(int v1, int v2) {
        // for(int i = 0; i < graph.get(v1).size(); i++) {
        //     if (graph.get(v1).get(i).v2 == v2) {
        //         graph.get(v1).remove(i);
        //     }
        // }

        // for (int i = 0; i < graph.get(v2).size(); i++) {
        //     if (graph.get(v2).get(i).v2 == v1) {
        //         graph.get(v2).remove(i);
        //     }
        // }

        int idx1 = getIdx(v1, v2);
        if (idx1 != -1) {
            graph.get(v1).remove(idx1);
        }

        int idx2 = getIdx(v2, v1);
        if (idx2 != -1) {
            graph.get(v2).remove(idx2);
        }
    }

    // ============ remove vertex
    static void removeVertex(int v1) {
        // graph.remove(v1);
        // for (int i = 0; i < graph.size(); i++) {
        //     for (int j = 0; j < graph.get(i).size(); j++) {
        //         if (graph.get(i).get(j).v2 == v1) {
        //             graph.get(i).remove(j);
        //         }
        //     }
        // }

        for (int i = 0; i < graph.get(v1).size(); i++) {
            Edge e = graph.get(v1).get(i);
            int idx = getIdx(e.v2, v1);
            graph.get(e.v2).remove(idx);
        }
        
        graph.remove(v1);
    }

    // has path =======================================
    static boolean hasPath(int v1, int v2, boolean[] visited) {
        if (v1 == v2) {
            return true;
        }

        visited[v1] = true;
        for (int i = 0; i < graph.get(v1).size(); i++) {
            if (visited[graph.get(v1).get(i).v2]) continue;
            boolean val = hasPath(graph.get(v1).get(i).v2, v2, visited);
            if (val == true) {
                return true;
            }
        }
        visited[v1] = false;
        return false;
    }

    // Print all paths ====================================

    static void PrintAllPaths(int v1, int v2, boolean[] visited, String asf) {
        if (v1 == v2) {
            System.out.println(asf + " " + v2);
            return;
        }

        visited[v1] = true;
        for (int i = 0; i < graph.get(v1).size(); i++) {
            if (visited[graph.get(v1).get(i).v2])
                continue;
            PrintAllPaths(graph.get(v1).get(i).v2, v2, visited, asf + " " + v1);
        }
        visited[v1] = false;
    }

    static boolean containsEdge (int v1, int v2) {
        return true;
    }


    // main ====================================
    public static void main(String[] args) {
        int n = 7;
        for (int i = 0; i < n; i++) {
            addVertex(i);
        }
        
        addEdge(0, 1, 10);
        addEdge(0, 3, 40);
        addEdge(1, 2, 10);
        addEdge(2, 3, 10);
        addEdge(3, 4, 2);
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
        // System.out.println(hasPath(0, 5, visited));
        PrintAllPaths(0, 5, visited, "");
    }
}