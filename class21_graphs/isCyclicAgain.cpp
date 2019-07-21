#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
	int nbr;

	Edge(int v) : nbr(v){};

	Edge(){};
};

class Node
{
public:
	int nbr;
	int parent;

	Node(int parent, Edge e) : parent(parent), nbr(e.nbr){};
	Node(int parent, int nbr) : parent(parent), nbr(nbr){};

	Node(){};
};

class Partite
{
public:
	int nbr;
	int toggle;

	Partite(Edge e, int toggle) : nbr(e.nbr), toggle(toggle)
	{
	}

	Partite(int nbr, int toggle) : nbr(nbr), toggle(toggle)
	{
	}
};

vector<vector<Edge>> graph;
int addEdge(int, int);

bool is_connected_graph()
{
	vector<bool> visited(graph.size(), false);
	queue<Edge> q;

	Edge root(0);
	q.push(root);

	while (!q.empty())
	{
		Edge remEdge = q.front();
		q.pop();
		if (visited[remEdge.nbr] == true)
		{
			continue;
		}

		visited[remEdge.nbr] = true;

		for (int i = 0; i < graph[remEdge.nbr].size(); i++)
		{
			Edge ne = graph[remEdge.nbr][i];
			if (visited[ne.nbr] == true)
				continue;
			q.push(ne);
		}
	}

	for (int i = 0; i < visited.size(); i++)
	{
		if (visited[i] == false)
			return false;
	}
	return true;
}

bool is_cyclic_graph()
{
	vector<bool> visited(graph.size(), false);
	queue<Node> q;

	Node root(0, 0);
	q.push(root);

	int prev;

	while (!q.empty())
	{
		Node remEdge = q.front();
		q.pop();
		if (visited[remEdge.nbr] == true)
		{
			return true;
		}

		visited[remEdge.nbr] = true;

		for (int i = 0; i < graph[remEdge.nbr].size(); i++)
		{
			Edge ne = graph[remEdge.nbr][i];

			if (visited[ne.nbr] == true)
			{
				if (ne.nbr != remEdge.parent)
					return true;
				else
					continue;
			}

			q.push(Node(remEdge.nbr, ne));
		}
		prev = remEdge.nbr;
	}
	return false;
}

bool is_bipartite()
{
	vector<int> visited(graph.size(), 0);
	queue<Partite> q;
	Partite root(0, 1);
	q.push(root);

	while (!q.empty())
	{
		Partite remNode = q.front();
		q.pop();

		if (visited[remNode.nbr] == remNode.toggle)
		{
			continue;
		}
		else if (visited[remNode.nbr] != 0)
		{
			return false;
		}

		visited[remNode.nbr] = remNode.toggle;
		for (int i = 0; i < graph[remNode.nbr].size(); i++)
		{
			int val = (remNode.toggle == 1) ? 2 : 1;

			Edge ne = graph[remNode.nbr][i];
			if (visited[ne.nbr] != 0)
			{
				if (visited[ne.nbr] != val)
					return false;
				else
					continue;
			}
			q.push(Partite(ne, val));
		}
	}
	return true;
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

	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(0, 3);
	addEdge(3, 4);
	addEdge(4, 5);
	addEdge(5, 6);
	addEdge(4, 6);
	addEdge(2, 5);

	cout << is_connected_graph() << "\n";
	cout << is_cyclic_graph() << "\n";
	cout << is_bipartite() << "\n";
}

// ______________________________
// ------------------------------
// ______________________________
int addEdge(int v1, int v2)
{
	Edge n1(v2);
	graph[v1].push_back(n1);

	Edge n2(v1);
	graph[v2].push_back(n2);
}
