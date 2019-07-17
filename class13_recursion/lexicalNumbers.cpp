#include<iostream>
using namespace std;

void lexicalPrintNumber(int lim, string ans) {
	if (ans != "" && stoi(ans) >= lim) {
		return;
	}
	if (ans != "") {
		cout << ans << endl;	
	}
	for(int i = 0; i <= 9; i++) {
		if (ans == "" && i == 0) continue;
		// cout << ans + to_string(i) << endl;
		lexicalPrintNumber(lim, ans + to_string(i));
	}
}

int main(int argc, char** argv) {
	int lim;
	cin >> lim;
	lexicalPrintNumber(lim, "");
}
