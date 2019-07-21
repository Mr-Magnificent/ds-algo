#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class DPair
{
public:
	int v;
	int c;
	string asf;

	bool operator<(const DPair &other) const
	{
		return this->c < other.c;
	}

	bool operator>(const DPair &other) const
	{
		return this->c > other.c;
	}

	DPair(int v, int c, string as = "") : v(v), c(c), asf(as) {}

	DPair() {}
};

class Edge {
	public:
	int nbr;
	int wt;
};

vector<vector<Edge>> graph;

void addEdge(int v1, int v2, int wt)
{
	Edge e1;
	e1.nbr = v2;
	e1.wt = wt;
	graph[v1].push_back(e1);

	Edge e2;
	e2.nbr = v1;
	e2.wt = wt;
	graph[v2].push_back(e2);
}


void dijkstra(int s) {
	priority_queue<DPair, vector<DPair>,greater<DPair>> pq;
	DPair rtp(s, 0, "0");
	vector<bool> visited(graph.size(), false);
	pq.push(rtp);
	while(!pq.empty()) {
		DPair rem = pq.top();
		pq.pop();
		if(visited[rem.v]) {
			continue;
		}
		cout << rem.asf << " @ " << rem.c << "\n";
		visited[rem.v] = true;
		for(int i = 0; i < graph[rem.v].size(); i++) {
			if (visited[graph[rem.v][i].nbr] == true) continue;
			Edge ne = graph[rem.v][i];
			DPair child(graph[rem.v][i].nbr, rem.c + ne.wt, rem.asf + to_string(graph[rem.v][i].nbr));
			pq.push(child);
		}
	}
}

int main(int argc, char **argv)
{
	graph.push_back(vector<Edge>()); // 0
	graph.push_back(vector<Edge>()); // 1
	graph.push_back(vector<Edge>()); // 2
	graph.push_back(vector<Edge>()); // 3
	graph.push_back(vector<Edge>()); // 4
	graph.push_back(vector<Edge>()); // 5
	graph.push_back(vector<Edge>()); // 6

	addEdge(0, 1, 10);
	addEdge(1, 2, 10);
	addEdge(2, 3, 10);
	addEdge(0, 3, 40);
	addEdge(3, 4, 2);
	addEdge(4, 5, 3);
	addEdge(5, 6, 3);
	addEdge(4, 6, 8);
	addEdge(2, 5, 5);

	dijkstra(0);
}