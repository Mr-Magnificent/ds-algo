#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge
{
public:
	int nbr;
	int wt;
};

vector<vector<Edge>> graph;

void hamiltonianPath(int ini, int source, int count, string ans, bool visited[], int len)
{

	if (count == len - 1)
	{
		ans += "->" + to_string(source);
		for (int i = 0; i < graph[source].size(); i++)
		{
			if (graph[source][i].nbr == ini)
			{
				ans += "*";
			}
		}
		cout << ans << endl;
	}

	for (int i = 0; i < graph[source].size(); i++)
	{
		if (visited[graph[source][i].nbr])
			continue;
		visited[source] = true;
		hamiltonianPath(ini, graph[source][i].nbr, count + 1, ans + "->" + to_string(source), visited, len);
		visited[source] = false;
	}
}

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

	bool visited[7]{false};
	hamiltonianPath(0, 0, 0, "", visited, 7);
}
