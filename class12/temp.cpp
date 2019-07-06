#include <bits/stdc++.h>
using namespace std;

// int main(int argc, char const *argv[])
// {
// 	string s = "ad"	;
// 	string ad = "ad"	;
// 	vector<int> *a = new vector<int> {1,2,3,4};
// 	vector<int> *c = new vector<int> {1,2,3,4};

// 	// vector<int> c = {1,2,3};
// 	if (a == c) {
// 		cout << "wow again" ;
// 	}
// 	if (s == ad)  {
// 		cout << "wow" << endl;
// 	}
// 	return 0;
// }

class Demo
{
	int a;

public:
	Demo(int x): a(x) {};

	int operator+(const Demo& d) {
		return this->a + d.a;
	}

	int operator+(const Demo * d) {
		return this->a + d->a;
	}
};

int main(int argc, char** argv) {

	Demo d1(2);
	Demo d2(3);
	cout << d1 + d2 << endl;

	Demo * d3 = new Demo(4);
	Demo * d4 = new Demo(5);
	cout << *d3+*d4 << endl;
	cout << d3->operator+(*d4) << endl;
	cout << d3->operator+(d4) << endl;
}