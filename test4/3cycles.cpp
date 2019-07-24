#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Edge
{
public:
	int nbr;
	int sum;
	int parent;
	int jump;

	Edge(int nbr, int parent, int jump = 0, int sum = 0) : nbr(nbr), parent(parent), jump(jump), sum(sum)
	{
	}
};

vector<int> find_cycle(vector<vector<int>> &graph, int i)
{
	vector<int> sol;
	Edge root(i, i);
	queue<Edge> q;
	q.push(root);

	while (!q.empty())
	{
		Edge rem = q.front();
		q.pop();

		if (rem.jump == 3 && rem.nbr == rem.parent) {
			sol.push_back(rem.sum);
		}

		if(rem.jump > 3) {
			return sol;
		}

		for(int i = 0; i < graph[rem.nbr].size(); i++) {
			q.push(Edge(graph[rem.nbr][i], rem.parent, rem.jump + 1, rem.sum + rem.nbr));
		}
	}

	return sol;
}

int all_cycles(vector<vector<int>> &graph)
{
	int count = 0;
	unordered_set<int> us;
	if (graph.size() < 3) return 0;
	for (int i = 0; i < graph.size(); i++)
	{
		vector<int> sum = find_cycle(graph, i);
		for (int x : sum)
		{
			if (us.count(x) == 0)
			{
				us.insert(x);
				count++;
			}
		}
	}
	return count;
}

void display(vector<vector<int>> &graph)
{
	for (int i = 0; i < graph.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	int t;
	cin >> t;
	vector<int> arr1;
	vector<int> arr2;
	for (int i = 0; i < t; i++)
	{
		int temp1;
		cin >> temp1;
		arr1.push_back(--temp1);
	}

	for (int i = 0; i < t; i++)
	{
		int temp1;
		cin >> temp1;
		arr2.push_back(--temp1);
	}

	for (int i = 0; i < t; i++)
	{
		if (arr1[i] == arr2[i]) continue;
		graph[arr1[i]].push_back(arr2[i]);
		graph[arr2[i]].push_back(arr1[i]);
	}
	// display(graph);
	cout << all_cycles(graph) << endl;
	return 0;
}