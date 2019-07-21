#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Coordinate
{
public:
	int x;
	int y;

	Coordinate(int a, int b) : x(a), y(b){};
};

void addToOnesQueue(vector<Coordinate> &ones, int i, int j)
{
	Coordinate *c = new Coordinate(i, j);
	ones.push_back(*c);
}

void addToQueue(vector<vector<int>> &field, vector<Coordinate> &ones, int i, int j)
{
	if (i + 1 < field.size() && field[i + 1][j] == 0)
	{
		field[i + 1][j] = 1;
		Coordinate *c = new Coordinate(i + 1, j);
		ones.push_back(*c);
	}
	if (i > 0 && field[i - 1][j] == 0)
	{
		field[i - 1][j] = 1;
		Coordinate *c = new Coordinate(i - 1, j);
		ones.push_back(*c);
	}
	if (j + 1 < field[0].size() && field[i][j + 1] == 0)
	{
		field[i][j + 1] = 1;
		Coordinate *c = new Coordinate(i, j + 1);
		ones.push_back(*c);
	}
	if (j > 0 && field[i][j - 1] == 0)
	{
		field[i][j - 1] = 1;
		Coordinate *c = new Coordinate(i, j - 1);
		ones.push_back(*c);
	}
}

void flashFire(vector<vector<int>> &field, int t)
{
	vector<Coordinate> ones;

	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field.size(); j++)
		{
			if (field[i][j] == 1)
			{
				addToOnesQueue(ones, i, j);
			}
		}
	}

	while (t--)
	{
		int len = ones.size();
		for(auto it = 0; it < len; it++) {
			Coordinate c = ones.front();
			ones.erase(ones.begin());
			addToQueue(field, ones, c.x, c.y);
		}
	}
}

int main(int argc, char **argv)
{
	vector<vector<int>> field = {
		{1, 2, 0, 2, 0, 0, 0},
		{0, 2, 0, 2, 0, 1, 0},
		{0, 0, 0, 2, 0, 0, 0},
		{2, 2, 2, 2, 2, 2, 0},
		{0, 2, 1, 0, 0, 0, 0},
		{0, 2, 0, 0, 0, 0, 0},
		{0, 2, 0, 0, 0, 0, 0}};

	int t;
	cout << "Enter time\t";
	cin >> t;
	flashFire(field, t);
	for(vector<int> row: field) {
		for(int ele: row) {
			cout << ele << " ";
		}
		cout << endl;
	}
}