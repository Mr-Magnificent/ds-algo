#include<iostream>
#include<vector>
using namespace std;

int stairs(int n, int jumps, vector<int>& qb) {
	if (n == 0) {
		return 1;
	}

	if (qb[n] != -1) {
		return qb[n];
	}

	int sol = 0;
	for (int i = 1; i <= jumps && n - i >= 0; i++) {
		sol += stairs(n - i, jumps, qb);
	}
	// qb[n] = sol;
	return sol;
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	int jumps;
	cin >> jumps;
	vector<int> qb(n + 1, -1);
	cout << stairs(n, jumps, qb) << endl;
}
