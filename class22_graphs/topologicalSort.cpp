#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Edge
{
public:
	int nbr;

	Edge(int nbr) : nbr(nbr)
	{
	}
};

vector<vector<Edge>> graph;

void addEdge(int, int);
void display_stack(stack<int> &);

void topological_comp(int i, vector<bool> &visited, stack<int> &order)
{
	visited[i] = true;
	for (int m = 0; m < graph[i].size(); m++)
	{
		if (visited[graph[i][m].nbr] == true)
			continue;
		topological_comp(graph[i][m].nbr, visited, order);
	}
	order.push(i);
}

void topological_sort()
{
	vector<bool> visited(graph.size(), false);
	stack<int> order;
	for (int i = 0; i < graph.size(); i++)
	{
		if (visited[i])
			continue;
		topological_comp(i, visited, order);
	}

	display_stack(order);
	cout << endl;
}

int main(int argc, char **argv)
{
	graph.push_back(vector<Edge>());
	graph.push_back(vector<Edge>());
	graph.push_back(vector<Edge>());
	graph.push_back(vector<Edge>());
	graph.push_back(vector<Edge>());
	graph.push_back(vector<Edge>());
	graph.push_back(vector<Edge>());

	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(0, 4);
	addEdge(4, 3);
	addEdge(5, 4);
	addEdge(5, 6);
	addEdge(6, 3);

	topological_sort();
}

void addEdge(int v1, int v2)
{
	Edge n1(v2);
	graph[v1].push_back(n1);
}

void display_stack(stack<int> &stk)
{
	while (!stk.empty())
	{
		int top = stk.top();
		stk.pop();
		cout << top << " ";
	}
}
