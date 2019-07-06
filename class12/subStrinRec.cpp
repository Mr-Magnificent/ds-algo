#include <bits/stdc++.h>
using namespace std;

vector<string> numMapping(string s, int begin, int group)
{
	if (begin == s.length()) {
		vector<string> s{""};
		return s;
	}

	int oneLen = stoi(s.substr(begin, group));
	int twoLen = stoi(s.substr(begin, group + 1));
	vector<string> mySol;
	if (oneLen < 27 && oneLen != 0 && begin < s.length())
	{
		vector<string> res = numMapping(s, begin + 1, group);
		for (string ele : res)
		{
			char temp = oneLen + 96;
			mySol.push_back(temp + ele);
		}
	}
	if (twoLen < 27 && twoLen != 0 && (begin + 1) < s.length())
	{
		vector<string> res = numMapping(s, begin + 2, group);
		for (string ele : res)
		{
			char temp = (char)twoLen + 96;
			mySol.push_back(temp + ele);
		}
	}
	return mySol;
}

int main(int argc, char **argv)
{
	string inp;
	cout << "Enter a numeric string: ";
	cin >> inp;
	vector<string> s = numMapping(inp, 0, 1);
	for(string ele: s)
	{
		cout << ele << endl;
	}
}