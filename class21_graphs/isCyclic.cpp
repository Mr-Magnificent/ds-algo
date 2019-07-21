#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class vertex
{
public:
	int vert;
	int toggle;

	vertex(int vert, int toggle): vert(vert), toggle(toggle) {};
};

vector<vector<int>> graph;

void addEdge(int v1, int v2)
{
	graph[v1].push_back(v2);
	graph[v2].push_back(v1);
}

bool isGcc(int ind, vector<bool> visited)
{
	queue<int> q;
	q.push(ind);

	while (!q.empty())
	{
		int rem = q.front();
		q.pop();
		if (visited[rem])
			continue;
		visited[rem] = true;
		for (int i = 0; i < graph[rem].size(); i++)
		{
			if (visited[graph[rem][i]])
				continue;
			q.push(graph[rem][i]);
		}
	}
	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

int isCyclic(int ind, vector<bool>& visited) {
	queue<int> q;
	q.push(ind);

	while (!q.empty())
	{
		int rem = q.front();
		q.pop();
		if (visited[rem])
			return rem;
		visited[rem] = true;
		for (int i = 0; i < graph[rem].size(); i++)
		{
			if (visited[graph[rem][i]])
				continue;
			q.push(graph[rem][i]);
		}
	}
	return -1;
}

vector<int> allCyclic() {
	vector<int> sol;
	for(int i = 0; i < graph.size(); i++) {
		vector<bool> allCycle(graph.size(), false);
		int val = isCyclic(i, allCycle);
		if (val != -1) {
			sol.push_back(val);
		}
	}
	return sol;
}

bool isBiparted(int ind, vector<int> visited) {
	queue<vertex> q;
	q.push(vertex(ind, 1));

	while(!q.empty()) {
		// cout << "fe";
		vertex rem = q.front();
		cout << rem.vert << " tog" << rem.toggle << " ";
		q.pop();
		int val = (rem.toggle == 1)? 2: 1;
		if (visited[rem.vert] == val) {
			return false;
		}
		visited[rem.vert] = rem.toggle;
		// if (visited[rem.vert] == rem.toggle) {
		// 	continue;
		// }
		for(int i = 0; i < graph[rem.vert].size(); i++) {
			if (visited[graph[rem.vert][i]] != 0) continue;
			int toggle = (rem.toggle == 1)? 2: 1;
			vertex *v = new vertex(graph[rem.vert][i], toggle);
			q.push(*v);
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	graph.push_back(vector<int>()); // 0
	graph.push_back(vector<int>()); // 1
	graph.push_back(vector<int>()); // 2
	graph.push_back(vector<int>()); // 3
	graph.push_back(vector<int>()); // 4
	graph.push_back(vector<int>()); // 5
	graph.push_back(vector<int>()); // 6

	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(0, 3);
	addEdge(3, 4);
	addEdge(4, 5);
	addEdge(5, 6);
	addEdge(4, 6);
	addEdge(2, 5);

	// vector<bool> visited(graph.size(), false);
	vector<int> visited(graph.size(), 0);
	// cout << gcc(0, visited) << endl;
	// bool isConnected = isGcc(0, visited);
	// vector<int> sol = allCyclic();

	cout << isBiparted(0, visited) << endl;
}