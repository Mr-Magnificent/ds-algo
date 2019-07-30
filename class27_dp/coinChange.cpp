#include <bits/stdc++.h>
using namespace std;

int val = 0;

void find_change_comb(vector<int> &coins, vector<int> &change_possible, int ind, int target)
{
	if (ind == coins.size())
	{
		return;
	}

	for (int i = 0; i < change_possible.size(); i++)
	{
		if (!change_possible[i])
			continue;
		change_possible[i + coins[ind]]++;
		if (i + coins[ind] == target)
			val++;
	}

	find_change_comb(coins, change_possible, ind + 1, target);
}

void find_change_perm(vector<int> &coins, vector<int> &change_possible, int ind, int target)
{
	if (ind == target)
	{
		return;
	}

	if (change_possible[ind] != 0)
	{
		for (int i = 0; i < coins.size(); i++)
		{
			if (ind + coins[i] > change_possible.size())
				continue;
			change_possible[ind + coins[i]] += change_possible[ind];
		}
	}

	find_change_perm(coins, change_possible, ind + 1, target);
}

int main(int argc, char **argv)
{
	vector<int> coins{2, 3, 5, 6};
	vector<int> change_possible(7 + 1, 0);
	change_possible[0] = 1;
	find_change_perm(coins, change_possible, 0, 7);
	cout << change_possible[change_possible.size() - 1] << endl;
}
