// import java.util.*;
#include <bits/stdc++.h>
using namespace std;

void floodFill(vector<vector <int>>& arr, int i, int j, string ans)
{
	if (i == arr.size() - 1 && j == arr[0].size() - 1)
	{
		cout << (ans) << endl;
		return;
	}
	if (i < 0 || i >= arr.size())
		return;
	if (j < 0 || j >= arr[0].size())
		return;
	if (arr[i][j] == 1)
		return;
	if (arr[i][j] == -1)
		return;
	arr[i][j] = -1;
	floodFill(arr, i + 1, j, ans + "D");
	floodFill(arr, i - 1, j, ans + "U");
	floodFill(arr, i, j + 1, ans + "R");
	floodFill(arr, i, j - 1, ans + "L");
	arr[i][j] = 0;
}

int main(int argc, char** argv)
{
	vector<vector <int>> v {
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1},
		{0, 1, 0, 1, 1, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
	};
	floodFill(v, 0, 0, "");
}
