#include <bits/stdc++.h>
using namespace std;

int FindMaxUnboundedKnapsack(vector<int> &wts, vector<int> &price, int bag_size)
{
	int *strg = new int[bag_size + 1]{};
	strg[0] = 0;
	for (int i = 1; i < bag_size + 1; i++)
	{
		for (int j = 0; j < wts.size(); j++)
		{
			if (i >= wts[j])
			{
				int factor = strg[i - wts[j]] + price[j];
				if (factor > strg[i])
				{
					strg[i] = factor;
				}
			}
		}
	}
	return strg[bag_size];
}

int main(int argc, char **argv)
{
	vector<int> wts{2, 5, 1, 3, 4};
	vector<int> price{15, 14, 10, 45, 30};
	int bag_size;
	cin >> bag_size;
	auto start = chrono::high_resolution_clock::now();
	cout << FindMaxUnboundedKnapsack(wts, price, bag_size) << endl;
	auto end = chrono::high_resolution_clock::now();
	cout << "\nTime taken " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
}