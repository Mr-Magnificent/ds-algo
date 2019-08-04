#include<bits/stdc++.h>
using namespace std;

int findPairsOrSingle(int n, vector<int> &strg) {
	if (n <= 0) {
		return 1;
	}
	if (strg[n] != -1) {
		return strg[n];
	}
	int count = findPairsOrSingle(n - 1, strg) + (n - 1) * findPairsOrSingle(n - 2, strg);
	strg[n] = count;
	return count;
}

int main(int argc, char** argv) {
	int n = 4;
	vector<int> strg(n + 1, -1);
	cout << findPairsOrSingle(n, strg) << endl;
}