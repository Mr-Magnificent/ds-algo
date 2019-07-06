#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> printMazePaths(int srcrow, int srccol,int destrow, int destcol) {

	if(srcrow == destrow && srccol == destcol) {
		return vector<string> {""};
	}
	 vector<string> sol1;
	vector<string> sol2;
	if (srcrow < destrow) {
		sol1 = printMazePaths(srcrow + 1, srccol, destrow, destrow);
	}
	if (srcrow < destrow) {
		sol2 = printMazePaths(srcrow, srccol + 1, destrow, destrow);
	}
	vector<string> mysol;
	for(string s: sol1) {
		mysol.push_back("x" + s);
	}
	for(string s: sol2) {
		mysol.push_back("y" + s);
	}
	return mysol;
}

int main(int argc, char** argv) {
	vector<string> s =printMazePaths(0,0, 2, 2);
	for(string ele: s) {
		cout << ele << endl;
	}
}