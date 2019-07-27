#include<iostream>
#include<vector>
#include<climits>
using namespace std;

string find_min_path(vector<int>& arr, vector<int>& jumps) {

	jumps[arr.size() - 1] = 0;

	// dp building smallest path by looking path cost of next *1 .. arr[i]* elements
	// and choosing the smallest from them and setting it to current min path by adding 1
	string sol = "";
	// - 2 because we already know the min path from jumps[arr.size() - 1] is zero
	for(int i = arr.size() - 2; i >= 0; i--) {
		int min = arr.size();

		for (int j = i + 1; j <= (i + arr[i]) && j < arr.size(); j++) {
			if (min > jumps[j]) {
				min = jumps[j];
			}
		}
		// increment the min path found by one
		jumps[i] = min + 1;
	}

	// at end the min path is stored in jump[0]
	cout << jumps[0] << endl;


	// Get min path
	int i = 0;
	sol += "0 ";
	while (i < jumps.size() - 1) {
		int minpos = i;
		int minJump = INT_MAX;
		for (int m = 1; m <= arr[i] && (i + m) < arr.size(); m++) {
			if (jumps[i + m] < minJump) {
				minpos = i + m;
				minJump = jumps[i + m];
			}
		}
		if (minpos == i) {
			return "No path found";
		}
		i = minpos;
		sol += to_string(minpos) + " ";
	}
	return sol;
}

int main(int argc, char** argv) {
	vector<int> v = {4, 2, 0, 0, 1, 1, 6, 3, 1, 0, 1, 2, 3, 1, 1};
	vector<int> min(v.size(), v.size());

	cout << find_min_path(v, min) << endl;
}
