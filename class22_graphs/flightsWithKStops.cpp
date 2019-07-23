// https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class PPair
{
public:
	int nbr;
	int cost;
	int jumps;
	string sol;

	PPair(int nbr, int cost, int jmp, string sol) : nbr(nbr), cost(cost), jumps(jmp), sol(sol)
	{
	}

	PPair() {}

	bool operator<(const PPair &other) const
	{
		return this->cost < other.cost;
	}

	bool operator>(const PPair &other) const
	{
		return this->cost > other.cost;
	}
};

class Edge
{
public:
	int nbr;
	int wt;

	Edge(int nbr, int wt) : nbr(nbr), wt(wt)
	{
	}

	void print()
	{
		cout << to_string(this->nbr) + " " + to_string(this->wt) << endl;
	}
};

void display(vector<vector<Edge>> flights)
{
	for (int i = 0; i < flights.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < flights[i].size(); j++)
		{
			cout << flights[i][j].nbr << " ";
		}
		cout << endl;
	}
}

class Solution
{
public:
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
	{
		vector<vector<Edge>> graph(n, vector<Edge>());

		for (int i = 0; i < flights.size(); i++)
		{
			vector<int> node = flights[i];
			graph[node[0]].push_back(Edge(node[1], node[2]));
		}
		// display(graph);
		cout << find_cheapest_path(src, dst, K, graph) << "\n";
	}

	int find_cheapest_path(int src, int dest, int k, vector<vector<Edge>> &graph)
	{
		priority_queue<PPair, vector<PPair>, greater<PPair>> q;
		PPair root(src, 0, 0, "");
		q.push(root);
		int min = INT_MAX;

		while (!q.empty())
		{
			PPair remNode = q.top();
			q.pop();

			if (remNode.nbr == dest)
			{
				return remNode.cost;
			}

			if (remNode.jumps == k + 1)
			{
				continue;
			}

			for (int i = 0; i < graph[remNode.nbr].size(); i++)
			{
				Edge ne = graph[remNode.nbr][i];
				PPair ele(ne.nbr, remNode.cost + ne.wt, remNode.jumps + 1, remNode.sol + to_string(remNode.nbr));
				q.push(ele);
			}
		}
		return -1;
	}
};

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	vector<vector<int>> flights;
	int tot;
	cin >> tot;
	for (int i = 0; i < tot; i++)
	{
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		flights.push_back(vector<int>({temp1, temp2, temp3}));
		// cout << flights[i][1] << endl;
	}
	// display(flights);
	int src, dest, k;
	cin >> src >> dest >> k;

	Solution sol;
	sol.findCheapestPrice(n, flights, src, dest, k);
}