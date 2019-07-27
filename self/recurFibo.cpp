#include<bits/stdc++.h>
using namespace std;

void recurFibo(int first, int second, int count, int total) {
	if (count == total) {
		return;
	}
	cout << first << " ";
	recurFibo(second, first + second, count+ 1, total);
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	recurFibo(0, 1, 0, n);
	cout << endl;
}