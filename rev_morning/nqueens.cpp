#include<bits/stdc++.h>
using namespace std;

static int c = 0;

vector<string> permutation(int ind, vector<vector<bool>>& board, int queen, int total) {
	if (queen == total) {
		c++;
		return vector<string>(1, "");
	}
	if (ind == board.size() * board.size()) {
		return vector<string>();
	}

	vector<string> mySol;

	for (int i = ind / board.size(); i < board.size(); i++) {
		for(int j = ind % board.size(); j < board.size(); j++)
		{
			if (board[i][j] == true) continue;

			board[i][j] = true;
			vector<string> sol1 = permutation(++ind, board, queen + 1, total);
			for(string asf: sol1) {
				mySol.push_back(" q" + to_string(queen) + "->[" + to_string(i) + ", " + to_string(j) + "], " + asf);
			}
			board[i][j] = false;
		}
	}
	return mySol;
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	vector<vector<bool>> board(n, vector<bool>(n, false));
	vector<string> sol = permutation(0, board, 0, board.size());
	for (string val: sol) {
		cout << val << endl;
	}
	cout << c << endl;
}