#include<bits/stdc++.h>
using namespace std;

int count_tiles(int n, int m, vector<int> &strg) {
	if (n == 0) {
		return 0;
	}
	if (n < m) {
		return n;
	}
	if (strg[n] != 0) {
		return strg[n];
	}

	int total = count_tiles(n - 1, m, strg) + count_tiles(n - m, m, strg);
	strg[n] = total;
	return total;
}

int main(int argc, char** argv) {
	int n = 10;
	int m = 2;
	vector<int> strg(n + 1, 0);
	cout << count_tiles(n, m, strg) << endl;
}
