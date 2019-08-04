#include <bits/stdc++.h>
using namespace std;

void find_max_profit(vector<int> &share_price, vector<int> &profit_so_far, vector<int> &max_till_now_pos)
{
	profit_so_far[0] = -share_price[0];
	for (int i = 1; i < share_price.size(); i++)
	{
		int max = -share_price[i];
		// if (profit_so_far[max_till_now_pos[i - 1]] > 0) {
		// 	max += profit_so_far[max_till_now_pos[i - 1]];
		// }
		for (int j = i - 1; j >= 0; j--)
		{
			int current_max_pos = max_till_now_pos[j];
			if (share_price[j] > share_price[i] - 3)
				continue;
			if (j > current_max_pos && profit_so_far[j] < 0 && share_price[i] - share_price[j] - 2 > max)
			{
				max = share_price[i] - share_price[j] - 2;
			}

			if (j > current_max_pos && profit_so_far[j] > 0 && share_price[i] - share_price[j] + profit_so_far[j] - 2 > max)
			{
				max = share_price[i] - share_price[j] + profit_so_far[j] - 2;
			}
		}
		if (max > profit_so_far[max_till_now_pos[i - 1]])
		{
			max_till_now_pos[i] = i;
		}
		else
		{
			max_till_now_pos[i] = max_till_now_pos[i - 1];
		}
		profit_so_far[i] = max;
	}
}

int main(int argc, char **argv)
{
	vector<int> share_price({1, 3, 9, 2000, 1999, 2001, 4, 10});
	vector<int> profit_so_far(share_price.size(), 0);
	vector<int> max_till_now_pos(share_price.size(), 0);
	find_max_profit(share_price, profit_so_far, max_till_now_pos);
	for (int x : profit_so_far)
	{
		cout << x << " ";
	}
	cout << endl;
	for (int x : max_till_now_pos)
	{
		cout << x << " ";
	}
	cout << endl;
}
