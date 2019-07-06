#include<iostream>
using namespace std;

void pi(int n) {
    if(n == 0) return;
    pi(n - 1);
    cout << n << " ";
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    pi(n);
    cout << endl;
}