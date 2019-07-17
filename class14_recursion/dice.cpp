#include<bits/stdc++.h>
using namespace std;

void diceSum(int target, string ans) {
	int sum = 0;
	for(int i = 0; i < ans.length(); i++) {
		sum += ans[i] - '0';
	}
	if(target == sum) {
		cout << ans << endl;
	}
	if (ans.length() > target) {
		return;
	}

	for(int i = 1; i <= 6; i++) {
		diceSum(target, ans + to_string(i));
	}
}

int main(int argc, char** argv) {
	diceSum(7, "");
}