#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void maze(vector<vector<int>> &arr, int i, int j, string sol)
{
	if (i == arr.size() - 1 && j == arr.size() - 1)
	{
		cout << sol << endl;
		return;
	}

	arr[i][j] = 2;

	if (i >= arr.size() || j >= arr.size() || i < 0 || j < 0)
	{
		return;
	}

	if (i < arr.size() - 1 && arr[i + 1][j] == 1 && i + 1)
	{
		maze(arr, i + 1, j, sol + 'D');
	}

	if (j > 0 && arr[i][j - 1] == 1)
	{
		maze(arr, i, j - 1, sol + 'L');
	}

	if (j < arr.size() - 1 && arr[i][j + 1] == 1)
	{
		maze(arr, i, j + 1, sol + 'R');
	}

	if (i > 0 && arr[i - 1][j] == 1)
	{
		maze(arr, i - 1, j, sol + 'U');
	}

	arr[i][j] = 1;
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			arr[i].push_back(temp);
		}
	}
	maze(arr, 0, 0, "");
	return 0;
}
