#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, k;
	vector<vector<int>> graph(k, vector<int>());
	cin >> k;
	vector<string> vec;
	for (int i = 0; i < k; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 0; i < vec.size() - 1; i++) {
		string s1 = vec[i];
		string s2 = vec[i + 1];
		while()
	}
	return 0;
}
