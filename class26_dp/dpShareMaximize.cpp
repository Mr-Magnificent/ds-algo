#include <bits/stdc++.h>
using namespace std;

int find_max_profit(vector<int> &share_price, vector<int> &profit_so_far, vector<int> &max_seen_so_far)
{
	for (int i = 0; i < share_price.size(); i++)
	{
		int max = -share_price[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (share_price[j] > share_price[i]) continue;
			if (share_price[i] - share_price[j] - 2 +)
		}
	}
}

int main(int argc, char **argv)
{
	vector<int> share_price = {9, 1, 3, 10, 1, 4, 6, 9};
	vector<int> profit_so_far(share_price.size(), 0);
	vector<int> max_seen_so_far(share_price.size(), 0);
	find_max_profit(share_price, profit_so_far, max_seen_so_far);
}