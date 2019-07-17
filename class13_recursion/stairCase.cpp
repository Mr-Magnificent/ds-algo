#include<bits/stdc++.h>
using namespace std;

void staircase(int a, int jumps, string ans) {
	if (a == 0) {
		cout << ans << endl;
		return;
	}
	if (a < 0) {
		return;
	}
	for(int i = 1; i <= jumps; i++) {
		staircase(a - i, jumps, to_string(i) + ans);
	}
}

int main(int argc, char** argv) {
	staircase(7, 3, "");
}