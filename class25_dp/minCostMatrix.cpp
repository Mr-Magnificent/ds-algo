#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Position
{
public:
	int x;
	int y;
	string sol;

	Position(int x, int y, string sol) : x(x), y(y), sol(sol)
	{
	}
};

void printAllPathBfs(vector<vector<int>> &sol)
{
	queue<Position> q;
	Position root(0, 0, "");
	q.push(root);
	while (!q.empty())
	{
		Position rem = q.front();
		q.pop();

		if (rem.x == sol.size() - 1 && rem.y == sol.size() - 1)
		{
			cout << rem.sol << endl;
			continue;
		}

		if (rem.x == sol.size() - 1 || rem.y == sol.size() - 1)
		{
			if (rem.x == sol.size() - 1)
			{
				q.push(Position(rem.x, rem.y + 1, rem.sol + to_string(sol[rem.x][rem.y + 1]) + " "));
			}
			if (rem.y == sol.size() - 1)
			{
				q.push(Position(rem.x + 1, rem.y, rem.sol + to_string(sol[rem.x + 1][rem.y]) + " "));
			}
			continue;
		}

		if (sol[rem.x + 1][rem.y] > sol[rem.x][rem.y + 1])
		{
			q.push(Position(rem.x, rem.y + 1, rem.sol + to_string(sol[rem.x][rem.y + 1]) + " "));
		}
		else if (sol[rem.x + 1][rem.y] < sol[rem.x][rem.y + 1])
		{
			q.push(Position(rem.x + 1, rem.y, rem.sol + to_string(sol[rem.x + 1][rem.y]) + " "));
		}
		else
		{
			q.push(Position(rem.x + 1, rem.y, rem.sol + to_string(sol[rem.x + 1][rem.y]) + " "));
			q.push(Position(rem.x, rem.y + 1, rem.sol + to_string(sol[rem.x][rem.y + 1]) + " "));
		}
	}
}

void printAllPathsDfs(vector<vector<int>> &sol)
{
	stack<Position> stk;
	Position root(0, 0, "");
	stk.push(root);
	while (!stk.empty())
	{
		Position rem = stk.top();
		stk.pop();
		// cout << sol[rem.x][rem.y] << " ";

		if (rem.x == sol.size() - 1 && rem.y == sol.size() - 1)
		{
			cout << rem.sol << endl;
			continue;
		}

		if (rem.x == sol.size() - 1 || rem.y == sol.size() - 1)
		{
			if (rem.x == sol.size() - 1)
			{
				stk.push(Position(rem.x, rem.y + 1, rem.sol + to_string(sol[rem.x][rem.y + 1]) + " "));
			}
			if (rem.y == sol.size() - 1)
			{
				stk.push(Position(rem.x + 1, rem.y, rem.sol + to_string(sol[rem.x + 1][rem.y]) + " "));
			}
			continue;
		}

		if (sol[rem.x + 1][rem.y] > sol[rem.x][rem.y + 1])
		{
			stk.push(Position(rem.x, rem.y + 1, rem.sol + to_string(sol[rem.x][rem.y + 1]) + " "));
		}
		else if (sol[rem.x + 1][rem.y] < sol[rem.x][rem.y + 1])
		{
			stk.push(Position(rem.x + 1, rem.y, rem.sol + to_string(sol[rem.x + 1][rem.y]) + " "));
		}
		else
		{
			stk.push(Position(rem.x + 1, rem.y, rem.sol + to_string(sol[rem.x + 1][rem.y]) + " "));
			stk.push(Position(rem.x, rem.y + 1, rem.sol + to_string(sol[rem.x][rem.y + 1]) + " "));
		}
	}
}

int cost(vector<vector<int>> &arr, vector<vector<int>> &sol)
{
	sol[arr.size() - 1][arr[0].size() - 1] = 0;

	int col_size = arr[0].size();
	int row_size = arr.size();
	for (int i = row_size - 2; i >= 0; i--)
	{
		sol[i][col_size - 1] = arr[i][col_size - 1] + sol[i + 1][col_size - 1];
	}

	for (int i = col_size - 2; i >= 0; i--)
	{
		sol[row_size - 1][i] = arr[row_size - 1][i] + sol[row_size - 1][i + 1];
	}

	for (int i = arr.size() - 2; i >= 0; i--)
	{
		for (int j = arr.size() - 2; j >= 0; j--)
		{
			int cost = min(sol[i + 1][j], sol[i][j + 1]);
			sol[i][j] = arr[i][j] + cost;
		}
	}

	cout << "DFS\n";
	printAllPathsDfs(sol);
	cout << endl;
	cout << "BFS\n";
	printAllPathBfs(sol);
	cout << endl;
	return sol[0][0];
}

int main(int argc, char **argv)
{
	// vector<vector<int>> arr = {
	// 	{2, 7, 3, 8, 0, 3, 7},
	// 	{4, 0, 1, 2, 4, 3, 4},
	// 	{3, 8, 5, 9, 0, 8, 1},
	// 	{1, 6, 0, 4, 5, 5, 2},
	// 	{6, 2, 9, 5, 7, 0, 6},
	// 	{0, 8, 7, 9, 6, 3, 0},
	// 	{1, 3, 5, 0, 5, 1, 0}};

	vector<vector<int>> arr = {
		{1, 5, 1, 0, 3},
		{1, 4, 0, 2, 3},
		{4, 0, 1, 3, 2},
		{2, 4, 0, 4, 1},
		{1, 2, 3, 2, 0}};

	vector<vector<int>> sol(arr.size(), vector<int>(arr[0].size(), 0));
	cout << cost(arr, sol) << endl;
}
