#include<iostream>
using namespace std;

void stack (int a) {
	cout << a << endl;
	stack(a + 1);
}

int main(int argc, char **argv) {
	stack(0);
}