#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// vector<vector<int>> graph;

void findConnected(vector<vector<int>> &graph, vector<bool> &visited, int ind)
{
	visited[ind] = true;
	for (int i = 0; i < graph[ind].size(); i++)
	{
		if (visited[graph[ind][i]])
			continue;
		findConnected(graph, visited, graph[ind][i]);
	}
}

int components(vector<vector<int>> &graph)
{
	int count = 0;
	vector<bool> visited(graph.size(), false);
	for (int i = 0; i < graph.size(); i++)
	{
		if (visited[i])
			continue;
		count++;
		findConnected(graph, visited, i);
	}
	return count;
}

void display(vector<vector<int>> &graph) {
	for (int i = 0; i < graph.size(); i++) {
		cout << i << ": ";
		for (int j = 0; j < graph[i].size(); j++) {
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
		graph[arr1[i]].push_back(arr2[i]);
		graph[arr2[i]].push_back(arr1[i]);
	}
	// display(graph);
	cout << components(graph) << endl;
	return 0;
}
