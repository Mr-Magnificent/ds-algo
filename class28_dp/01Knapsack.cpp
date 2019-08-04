#include <bits/stdc++.h>
#include <cassert>
// #include<chrono>
using namespace std;

int FindMaxItemsPrice(vector<int> &wts, vector<int> &price, const int bag_size)
{
	int **strg = new int *[wts.size()];
	for (int i = 0; i < wts.size(); i++)
	{
		strg[i] = new int[bag_size + 1]{0};
	}

	for (int i = 0; i < wts.size(); i++)
	{
		for (int j = 1; j <= bag_size; j++)
		{
			if (i == 0)
			{
				if (j >= wts[i])
					strg[i][j] = price[i];
			}
			else
			{
				strg[i][j] = strg[i - 1][j];
				if (j >= wts[i])
				{
					int factor = price[i] + strg[i - 1][j - wts[i]];
					if (factor > strg[i][j])
					{
						strg[i][j] = factor;
					}
				}
			}
		}
	}
	return strg[wts.size() - 1][bag_size];
}

int main(int argc, char **argv)
{
	vector<int> wts{2, 5, 1, 3, 4};
	vector<int> price{15, 14, 10, 45, 30};
	int bag_size;
	cin >> bag_size;
	// assert(bag_size == 7);
	auto start = chrono::high_resolution_clock::now();
	cout << FindMaxItemsPrice(wts, price, bag_size) << endl;
	auto end = chrono::high_resolution_clock::now();
	cout << "\nTime taken is " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
	return 0;
}