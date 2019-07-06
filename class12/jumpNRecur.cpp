// #include<iostream>
// #include<vector>
#include <bits/stdc++.h>
// #include<string>
using namespace std;
int c=0;
vector<string> jumpN(int srcrow, int srccol, int destrow, int destcol)
{
	if (srcrow == destrow && srccol == destcol)
	{
		vector<string> s{""};
		c++;
		return s;
	}
	else if (srcrow > destrow)
	{
		vector<string> s;
		return s;
	}
	else if (srccol > destcol)
	{
		vector<string> s;
		return s;
	}

	vector<string> mySol;
	for (int i = srcrow + 1; i <= destrow; i++)
	{
		vector<string> sol = jumpN(i, srccol, destrow, destcol);
		for (string s : sol)
		{
			mySol.push_back("V" + to_string(i - srcrow) + s);
		}
	}
	for (int i = srccol + 1; i <= destcol; i++)
	{
		vector<string> sol = jumpN(srcrow, i, destrow, destcol);
		for (string s : sol)
		{
			mySol.push_back("H" + to_string(i - srccol) + s);
		}
	}

	int tot = ((destrow - srcrow) > (destcol - srccol)) ? (destcol - srccol) : (destrow - srcrow);
	for (int i = 1; i <= tot; i++)
	{
		vector<string> sol = jumpN(srcrow + i, srccol + i, destrow, destcol);
		for (string s : sol)
		{
			mySol.push_back("D" + to_string(i) + s);
		}
	}
	return mySol;
}

int main(int argc, char **argv)
{
	vector<string> s = jumpN(0, 0, 2, 2);
	for (string ele : s)
	{
		cout << ele << endl;
	}
	cout<<c<<endl;
}