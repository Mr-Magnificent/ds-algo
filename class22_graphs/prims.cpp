#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
	int nbr;
	int wt;

	Edge(int v, int wt) : nbr(v), wt(wt)
	{
	}
};

class PPair
{
public:
	int v;
	int pv;
	int c;

	PPair(int v, int pv, int c) : v(v), pv(pv), c(c)
	{
	}

	bool operator<(const PPair &other) const
	{
		return this->c < other.c;
	}

	bool operator>(const PPair &other) const
	{
		return this->c > other.c;
	}
};

vector<vector<Edge>> graph;
int addEdge(int, int, int);
void addEdge(vector<vector<Edge>> &, int, int, int);
void display(vector<vector<Edge>> &);

void minimum_spanning_tree()
{
	vector<vector<Edge>> mst(graph.size(), vector<Edge>());
	priority_queue<PPair, vector<PPair>, greater<PPair>> q;
	PPair root(0, -1, 0);

	vector<bool> visited(graph.size(), false);
	q.push(root);

	while (!q.empty())
	{
		PPair rem = q.top();
		q.pop();
		if (visited[rem.v] == true)
			continue;

		visited[rem.v] = true;

		if (rem.pv != -1)
		{
			addEdge(mst, rem.pv, rem.v, rem.c);
		}
		for (int i = 0; i < graph[rem.v].size(); i++)
		{
			if (visited[graph[rem.v][i].nbr] == true)
				continue;
			Edge ne = graph[rem.v][i];
			q.push(PPair(graph[rem.v][i].nbr, rem.v, ne.wt));
		}
	}
	display(mst);
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

	addEdge(0, 1, 20);
	addEdge(1, 2, 10);
	addEdge(2, 3, 30);
	addEdge(0, 3, 40);
	addEdge(3, 4, 2);
	addEdge(4, 5, 3);
	addEdge(5, 6, 3);
	addEdge(4, 6, 8);
	// addEdge(2, 5);

	minimum_spanning_tree();
}

// ______________________________
// ------------------------------
// ______________________________
int addEdge(int v1, int v2, int wt)
{
	Edge n1(v2, wt);
	graph[v1].push_back(n1);

	Edge n2(v1, wt);
	graph[v2].push_back(n2);
}

void addEdge(vector<vector<Edge>> &mst, int v1, int v2, int wt)
{
	Edge n1(v2, wt);
	mst[v1].push_back(n1);

	Edge n2(v1, wt);
	mst[v2].push_back(n2);
}

void display(vector<vector<Edge>> &m)
{
	for (int v = 0; v < m.size(); v++)
	{
		cout << v << " -> ";
		for (int e = 0; e < m[v].size(); e++)
		{
			cout << " [" << m[v][e].nbr << " - " << m[v][e].wt << "], ";
		}
		cout << endl;
	}
}
