#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Position
{
public:
	int x;
	int y;
	int cost;

	Position(int x, int y, int cost = 0) : x(x), y(y), cost(cost)
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
};

int findTarget(vector<vector<bool>> &board, int i, int j, int tari, int tarj)
{
	Position root(i, j);
	priority_queue<Position, vector<Position>, greater<Position>> pq;
	pq.push(root);

	while (!pq.empty())
	{
		Position rem = pq.top();
		pq.pop();

		if (board[rem.x][rem.y] == true)
		{
			continue;
		}

		if (rem.x == tari && rem.y == tarj)
		{
			return rem.cost;
		}

		board[rem.x][rem.y] = true;
		if (rem.x > 0 && rem.y < board.size() - 2 && board[rem.x - 1][rem.y + 2] != true)
		{
			pq.push(Position(rem.x - 1, rem.y + 2, rem.cost + 1));
		}

		if (rem.x < board.size() - 1 && rem.y < board.size() - 2 && board[rem.x + 1][rem.y + 2] != true)
		{
			pq.push(Position(rem.x + 1, rem.y + 2, rem.cost + 1));
		}

		if (rem.x < board.size() - 2 && rem.y < board.size() - 1 && board[rem.x + 2][rem.y + 1] != true)
		{
			pq.push(Position(rem.x + 2, rem.y + 1, rem.cost + 1));
		}

		if (rem.x > 1 && rem.y < board.size() - 1 && board[rem.x - 2][rem.y + 1] != true)
		{
			pq.push(Position(rem.x - 2, rem.y + 1, rem.cost + 1));
		}

		if (rem.x > 1 && rem.y > 0 && board[rem.x - 2][rem.y - 1] != true)
		{
			pq.push(Position(rem.x - 2, rem.y - 1, rem.cost + 1));
		}

		if (rem.x < board.size() - 2 && rem.y > 0 && board[rem.x + 2][rem.y - 1] != true)
		{
			pq.push(Position(rem.x + 2, rem.y - 1, rem.cost + 1));
		}

		if (rem.x < board.size() - 1 && rem.y > 1 && board[rem.x + 1][rem.y - 2] != true)
		{
			pq.push(Position(rem.x + 1, rem.y - 2, rem.cost + 1));
		}

		if (rem.x > 0 && rem.y > 1 && board[rem.x - 1][rem.y - 2] != true)
		{
			pq.push(Position(rem.x - 1, rem.y - 2, rem.cost + 1));
		}
	}
	return -1;
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;

	cin >> n;
	vector<vector<bool>> board(n, vector<bool>(n, false));
	int i, j;
	cin >> i >> j;
	int tari, tarj;
	cin >> tari >> tarj;
	cout << findTarget(board, i - 1, j - 1, tari - 1, tarj - 1) << endl;
	return 0;
}
