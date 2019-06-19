#include<iostream>
using namespace std;

int main(int argc, char** argv) {
    int n;
    cout << "Enter the number\n";
    cin >> n;
    while (n != 0) {
        cout << (n % 10);
        n /= 10;
    }
    cout << endl;
}