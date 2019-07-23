#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Position
{
public:
	int position;
	int cost;
	int buffer;
	string sol;

	Position(int position, int cost, string sol, int buffer) : position(position), cost(cost), sol(sol), buffer(buffer)
	{
	}

	Position(int position) : position(position), cost(0), sol(""), buffer(0)
	{
	}

	void setPosition(int position, int cost, string sol, int buffer)
	{
		this->position = position;
		this->cost = cost;
		this->sol = sol;
		this->buffer = buffer;
	}

	Position()
	{
	}

	bool operator<(const Position &other) const
	{
		return this->cost < other.cost;
	}

	bool operator>(const Position &other) const
	{
		return this->cost > other.cost;
	}

	string operator<<(const Position &other) const
	{
		return this->position + " " + this->cost;
	}
};

vector<vector<int>> graph;

void add_edge(int, int);
void add_snakes_and_ladders(vector<int>);

void print_minimum_path(int dest)
{
	priority_queue<Position, vector<Position>, greater<Position>> q;
	vector<bool> visited(graph.size(), false);
	Position root(0);
	q.push(root);

	while (!q.empty())
	{
		Position remNode = q.top();
		q.pop();
		if (remNode.position == dest)
		{
			cout << remNode.sol + " " + to_string(dest) + "\n";
			cout << remNode.cost + 1 << endl;
			return;
		}
		if (visited[remNode.position] == true)
			continue;
		visited[remNode.position] = true;
		for (int i = 0; i < graph[remNode.position].size(); i++)
		{
			int nbr = graph[remNode.position][i];

			Position p;
			if (remNode.buffer == 6 || nbr != remNode.position + 1)
			{
				p.setPosition(nbr, remNode.cost + 1, remNode.sol + " " + to_string(remNode.position), 0);
			}
			else
			{
				p.setPosition(nbr, remNode.cost, remNode.sol + " " + to_string(remNode.position), remNode.buffer + 1);
			}
			q.push(p);
		}
	}
	cout << "No solution\n";
}

int main(int argc, char **argv)
{
	int rows;
	cout << "Enter the number of rows\t";
	cin >> rows;
	for (int i = 0; i < rows * 10; i++)
	{
		graph.push_back(vector<int>());
	}

	for (int i = 0; i < graph.size() - 1; i++)
	{
		add_edge(i, i + 1);
	}

	vector<int> snl(graph.size(), -1);
	snl[2] = 27;
	snl[7] = 14;
	snl[23] = 4;
	snl[28] = 5;

	add_snakes_and_ladders(snl);
	print_minimum_path((rows * 10) - 1);
}

// -----------------------------------------------
void add_edge(int v1, int v2)
{
	graph[v1].push_back(v2);
}

void add_snakes_and_ladders(vector<int> connections)
{
	for (int i = 0; i < connections.size(); i++)
	{
		if (connections[i] == -1)
			continue;
		graph[i].push_back(connections[i]);
	}
}