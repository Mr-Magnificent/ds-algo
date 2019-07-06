#include<bits/stdc++.h>
using namespace std;

vector<string> loop (int *arr, int ind, int size) {
	if(ind == size) {
		vector<string> s{""};
		return s;
	}
	else if (ind > size) {
		vector<string> s;
		return s;
	}
	vector<string> mysol;
	for(int i = 1; i <= arr[ind]; i++) {
		vector<string> sol = loop(arr, ind + i, size);
		for(string path: sol) {
			mysol.push_back(to_string(ind) + path);
		}
	}
	return mysol;
}

int main(int argc, char** argv) {
	int* arr = new int[11] {3,2,5,2,0,1,2,0,2,1};
	vector<string> s = loop(arr, 0, 10);
	for(string path: s) {
		cout << path << endl;
	}
}