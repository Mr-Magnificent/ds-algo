#include <bits/stdc++.h>
using namespace std;

void find_path(vector<vector<bool>> &found, vector<int> &arr, int n)
{
	if (n == arr.size())
	{
		return;
	}

	for (int i = 0; i < found[0].size(); i++)
	{
		if (!found[n - 1][i])
			continue;

		found[n][i] = true;
		if (i + arr[n] < found[0].size())
		{
			found[n][i + arr[n]] = true;
		}
	}
	find_path(found, arr, n + 1);
}

void show_all_paths(vector<int> &arr, vector<vector<bool>> &found, int i, int j, string asf)
{
	if (i == 0)
	{
		if (j == 0)
		{
			cout << asf << endl;
		}
		else if (j == arr[0])
		{
			cout << asf + " " + to_string(j) << endl;
		}
		return;
	}

	if (found[i - 1][j])
	{
		show_all_paths(arr, found, i - 1, j, asf);
	}

	if (j - arr[i] >= 0 && found[i - 1][j - arr[i]])
	{
		show_all_paths(arr, found, i - 1, j - arr[i], asf + " " + to_string(arr[i]));
	}
}

int main(int argc, char **argv)
{
	vector<int> arr = {3, 2, 5, 1, 8};
	int n;
	cin >> n;
	vector<vector<bool>> found(arr.size(), vector<bool>(n + 1, false));

	for (int i = 0; i < arr.size(); i++)
	{
		found[i][0] = true;
	}
	if (arr[0] < arr.size() && arr[0] >= 0)
	{
		found[0][arr[0]] = true;
	}

	find_path(found, arr, 1);
	cout << found[arr.size() - 2][n] << endl;
	show_all_paths(arr, found, arr.size() - 1, n, "");
}