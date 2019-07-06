#include <bits/stdc++.h>
using namespace std;

vector<string> stepRec(int step, int jump, int maxJump)
{
	if (step <= 0)
	{
		vector<string> v{""};
		return v;
	}

	vector<string> myRes;
	for (int i = 1; i <= maxJump; i++)
	{
		vector<string> res = stepRec(step - i, i, maxJump);
		for (string ele : res)
		{
			int sum = 0;
			for (int i = 0; i < ele.length(); i++)
			{
				sum += ele[i] - '0';
			}
			if ((sum + i) == step)
				myRes.push_back(to_string(i) + ele);
		}
	}
	return myRes;
}

int main(int argc, char **argv)
{
	int stairs;
	int maxstepsize;
	cout << "Enter the number of stairs: ";
	cin >> stairs;
	cout << "Enter the max step size:    ";
	cin >> maxstepsize;

	vector<string> s = stepRec(stairs, maxstepsize, maxstepsize);
	for (string t : s)
	{
		cout << t << endl;
	}
	return 0;
}