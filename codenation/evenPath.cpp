#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Edge
{
public:
	int nbr;

	Edge(int nbr) : nbr(nbr)
	{
	}
};

int te;

void allPaths(vector<vector<Edge>>& graph, int source, int dest, int count) {
	count += 1;

	if(source == dest) {
		if (count % 2 == 0) {
			te++;
			return;
		} else {
			return;
		}
	}

	for(int i = 0; i < graph[source].size(); i++) {
		allPaths(graph, graph[source][i].nbr, dest, count);
	}
}

void traverse(vector<vector<Edge>> &graph, int source)
{
	for (int i = 0; i < graph.size(); i++)
	{
		te = 0;

		allPaths(graph,  source, i, 0);
		// val += te;
		cout << te << " ";
	}
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x;
		cin >> n >> m >> x;
		x--;
		vector<vector<Edge>> graph;
		for (int i = 0; i < n; i++)
		{
			graph.push_back(vector<Edge>());
		}

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			graph[u].push_back(Edge(v));
		}
		traverse(graph, x);
		cout << "\n";
	}
	return 0;
}
