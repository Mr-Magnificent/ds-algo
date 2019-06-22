#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;
    cout << "Enter the number of rows for pattern\t";
    cin >> n;
    for(int i = 0 ; i <  n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                cout << " * ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
}
