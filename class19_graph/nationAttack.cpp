#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> graph;

void addEdge(int v1, int v2)
{
	graph[v1].push_back(v2);

	graph[v2].push_back(v1);
}



// Counts the total teams possible
void totalTeams(vector<int> val) {
	int mul = 0;
	for(int i = 0; i < val.size(); i++) {
		for(int j = i + 1; j < val.size(); j++) {
			mul += val[i] * val[j];
		}
	}
	cout << mul << endl;
}

// Counts the total members from a country
int countPersons(int ind, vector<bool> &visited)
{
	if (visited[ind])
	{
		return 0;
	}

	int count = 1;
	visited[ind] = true;
	for (int i = 0; i < graph[ind].size(); i++)
	{
		int val = countPersons(graph[ind][i], visited);
		count += val;
	}
	return count;
}


//	returns the total countries with their members
vector<int> createNation(int ind, int people, vector<bool> &visited)
{
	vector<int> mySol;

	for (int i = 0; i < people; i++)
	{
		int count = countPersons(i, visited);
		if (count != 0)
		{
			mySol.push_back(count);
		}
	}
	return mySol;
}

int main(int argc, char **argv)
{
	int arr1[] = {2, 3, 8, 1, 6, 4};
	int arr2[] = {9, 8, 7, 7, 5, 2};
	int len = 6;
	int people;
	cout << "Enter total people\t";
	cin >> people;
	for (int i = 0; i < people; i++)
	{
		graph.push_back(vector<int>());
	}
	for (int i = 0; i < len; i++)
	{
		addEdge(arr1[i], arr2[i]);
	}

	vector<bool> visited(6, false);
	vector<int> nations = createNation(0, people, visited);

	totalTeams(nations);
}