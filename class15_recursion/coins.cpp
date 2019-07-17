#include<bits/stdc++.h>
using namespace std;

void diceSum(int target, int* coins, int tot, string ans, int ci) {
	int sum = 0;
	for(int i = 0; i < ans.length(); i++) {
		sum += ans[i] - '0';
	}
	if(target == sum) {
		cout << ans << endl;
		return;
	}
	if (target < sum) {
		return;
	}
	if (ci == tot) {
		return;
	}

	for(int i = ci; i < tot; i++) {
		diceSum(target, coins, tot, ans + to_string(coins[i]), i);
	}
}

int main(int argc, char** argv) {
	int arr[] = {2,3,5,6};
	diceSum(9, arr, 4, "", 0);
}