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

void display()
{
	for (int v = 0; v < graph.size(); v++)
	{
		cout << v << " -> ";
		for (int e = 0; e < graph[v].size(); e++)
		{
			cout << " [" << graph[v][e].nbr << " - " << graph[v][e].wt << "], ";
		}
		cout << endl;
	}
}

bool hasPath(int ini, int f, bool visited[])
{
	if (ini == f)
	{
		return true;
	}

	for (int i = 0; i < graph[ini].size(); i++)
	{
		if (visited[graph[ini][i].nbr])
			continue;
		visited[ini] = true;
		bool val = hasPath(graph[ini][i].nbr, f, visited);
		// visited[ini] = false;
		if (val)
			return val;
	}
	return false;
}

void printAllPaths(int ini, int final, string asf, bool visited[])
{
	if (ini == final)
	{
		cout << asf + to_string(final) << endl;
	}
	for (int i = 0; i < graph[ini].size(); i++)
	{
		if (visited[graph[ini][i].nbr])
			continue;
		visited[ini] = true;
		printAllPaths(graph[ini][i].nbr, final, asf + to_string(ini) + " ", visited);
		visited[ini] = false;
	}
}

int printSmallestPath(int ini, int final, string asf, bool visited[])
{
	if (ini == final)
	{
		return 0;
	}

	int weight = INT_MAX;
	for (int i = 0; i < graph[ini].size(); i++)
	{
		if (visited[graph[ini][i].nbr])
			continue;

		visited[ini] = true;
		int temp = printSmallestPath(graph[ini][i].nbr, final, asf + to_string(ini) + " ", visited);
		if (temp != INT_MAX && (temp + graph[ini][i].wt) < weight)
		{
			weight = temp + graph[ini][i].wt;
		}
		visited[ini] = false;
	}
	return weight;
}

int printLargestPath(int ini, int final, string asf, bool visited[])
{
	if (ini == final)
	{
		return 0;
	}

	int weight = INT_MIN;
	for (int i = 0; i < graph[ini].size(); i++)
	{
		if (visited[graph[ini][i].nbr])
			continue;

		visited[ini] = true;
		int temp = printSmallestPath(graph[ini][i].nbr, final, asf + to_string(ini) + " ", visited);
		if (temp != INT_MIN && (temp + graph[ini][i].wt) > weight)
		{
			weight = temp + graph[ini][i].wt;
		}
		visited[ini] = false;
	}
	return weight;
}

int minHops(int ini, int final, bool visited[])
{
	if (ini == final)
	{
		return 0;
	}

	int minHop = INT_MAX;
	for (int i = 0; i < graph[ini].size(); i++)
	{
		visited[ini] = true;
		if (visited[graph[ini][i].nbr])
			continue;
		int hops = minHops(graph[ini][i].nbr, final, visited);
		if (hops != INT_MAX && (hops + 1) < minHop)
		{
			minHop = hops + 1;
		}
		visited[ini] = false;
	}
	return minHop;
}

int printCeilPath(int ini, int final, string asf, int given, bool visited[])
{
	if (ini == final)
	{
		return 0;
	}

	int weight = INT_MAX;
	for (int i = 0; i < graph[ini].size(); i++)
	{
		if (visited[graph[ini][i].nbr])
			continue;

		visited[ini] = true;
		int temp = printSmallestPath(graph[ini][i].nbr, final, asf + to_string(ini) + " ", visited);
		if (temp != INT_MAX && (temp + graph[ini][i].wt) < weight && (temp + graph[ini][i].wt) > given)
		{
			weight = temp + graph[ini][i].wt;
		}
		visited[ini] = false;
	}
	return weight;
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

	bool visited[7]{false};

	display();
	// cout << (hasPath(0, 6, visited)) << endl;
	cout << printSmallestPath(0, 6, "", visited) << endl;
	cout << printLargestPath(0, 6, "", visited) << endl;
	// cout << minHops(0, 6, visited) << endl;
	cout << printCeilPath(0, 6, "", 35, visited) << endl;
}
