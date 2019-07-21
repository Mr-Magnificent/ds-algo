#include<iostream>
#include<queue>
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

bool bfs(int s, int d) {
	vector<bool> visited (graph.size(), false);
	queue<int> q;

	q.push(s);
	while(!q.empty()) {
		int rem = q.front();
		q.pop();
		visited[rem] = true;
		if (rem == d) return true;
		cout << rem << endl;
		for(int i = 0; i < graph[rem].size(); i++) {
			if(visited[graph[rem][i].nbr]) continue;
			q.push(graph[rem][i].nbr);
		}
	}
	return false;
}

string connectedSingleComponent(int ind, vector<bool>& visited) {
	string csc = "";
	queue<int> q;
	q.push(ind);
	while(!q.empty()) {
		int rem = q.front();
		q.pop();

		if (visited[rem]) continue;
		visited[rem] = true;

		csc += to_string(rem);

		for(int i = 0; i < graph[rem].size(); i++) {
			if (visited[graph[rem][i].nbr]) continue;

			q.push(graph[rem][i].nbr);
		}
	}
	return csc;
}

vector<string> connectedComponents () {
	vector<string> mySol;
	vector<bool> visited(graph.size(), false);

	for (int i = 0; i < graph.size(); i++) {
		if (visited[i]) continue;
		mySol.push_back(connectedSingleComponent(i, visited));
	}
	return mySol;
}


int main(int argc, char** argv) {
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
	// addEdge(3, 4, 2);
	addEdge(4, 5, 3);
	addEdge(5, 6, 3);
	addEdge(4, 6, 8);
	// addEdge(2, 5, 5);

	// cout << bfs(0, 6) << endl;
	vector<string> sol = connectedComponents();
	for(string s: sol) {
		cout << s << endl;
	}
}