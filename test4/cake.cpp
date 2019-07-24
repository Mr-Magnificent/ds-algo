#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int piece_size(vector<vector<int>> &arr, int i, int j)
{
	int count = 1;

	arr[i][j] = 2;
	if (i > 0 && arr[i - 1][j] == 1)
	{
		count += piece_size(arr, i - 1, j);
	}

	if (j > 0 && arr[i][j - 1] == 1)
	{
		count += piece_size(arr, i, j - 1);
	}

	if (j < arr.size() - 1 && arr[i][j + 1] == 1)
	{
		count += piece_size(arr, i, j + 1);
	}

	if (i < arr.size() - 1 && arr[i + 1][j] == 1)
	{
		count += piece_size(arr, i + 1, j);
	}
	return count;
}

int find_biggest_piece(vector<vector<int>> &arr)
{
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[i][j] == 1)
			{
				int retval = piece_size(arr, i, j);
				if (retval > count)
					count = retval;
			}
		}
	}
	return count;
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	cout << find_biggest_piece(arr) << endl;
	return 0;
}
