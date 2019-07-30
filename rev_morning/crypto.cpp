#include <bits/stdc++.h>
using namespace std;

vector<bool> find_unique_chars(string first, string second, string ans)
{
	vector<bool> sol(26, false);
	for (int i = 0; i < first.size(); i++)
	{
		sol[first[i] - 'a'] = true;
	}

	for (int i = 0; i < second.size(); i++)
	{
		sol[second[i] - 'a'] = true;
	}

	for (int i = 0; i < ans.size(); i++)
	{
		sol[ans[i] - 'a'] = true;
	}

	return sol;
}

int find_numeral_val(string str, vector<int> val_assigned)
{
	int val = 0;
	for (int i = 0; i < str.length(); i++)
	{
		val = val * 10 + val_assigned[(str[i] - 'a')];
	}
	return val;
}

string get_unique_char_string(vector<bool> &uniq_char_arr)
{
	string s = "";
	for (int i = 0; i < uniq_char_arr.size(); i++)
	{
		if (!uniq_char_arr[i])
			continue;
		s += (char)(i + 'a');
	}
	return s;
}

vector<vector<int>> find_sols(vector<int> &val_assigned, string &unique_chars, vector<bool> &val_avail,
							  string sol, string first, string second, int ind)
{
	if (ind == unique_chars.size())
	{
		int fir = find_numeral_val(first, val_assigned);
		int sec = find_numeral_val(second, val_assigned);
		int third = find_numeral_val(sol, val_assigned);
		if (third == (fir + sec))
		{
			return vector<vector<int>>(1, vector<int>({fir, sec, third}));
		}
		else
		{
			return vector<vector<int>>();
		}
	}

	vector<vector<int>> mySol;
	for (int i = 0; i < val_avail.size(); i++)
	{
		if (val_avail[i])
			continue;
		val_avail[i] = true;
		val_assigned[unique_chars[ind] - 'a'] = i;
		vector<vector<int>> tempsol = find_sols(val_assigned, unique_chars, val_avail, sol, first, second, ind + 1);
		val_avail[i] = false;
		for (auto row : tempsol)
		{
			mySol.push_back(row);
		}
	}
	val_assigned[unique_chars[ind] - 'a'] = -1;
	return mySol;
}

int main(int argc, char **argv)
{
	string first, second, sol;
	cin >> first >> second >> sol;
	vector<bool> unique_chars_arr = find_unique_chars(first, second, sol);
	string unique_chars = get_unique_char_string(unique_chars_arr);
	cout << unique_chars << endl;
	vector<int> val_assigned(26, -1);
	vector<bool> val_available(10, false);
	vector<vector<int>> ans = find_sols(val_assigned, unique_chars, val_available, sol, first, second, 0);
	for (vector<int> row : ans)
	{
		for (int ele : row)
		{
			cout << ele << " ";
		}
		cout << endl;
	}
	cout << ans.size() << endl;
}
