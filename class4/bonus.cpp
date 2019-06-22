#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << " " << j << " ";
        }
        for (int j = 1; j <= ((2 * n - 1) - (2 * i)); j++) {
            cout << "   ";
        }
        int j = (i != n) ? i: i - 1;
        for (; j >= 1; j--) {   
            cout << " " << j << " ";
        }
        cout << endl;
    }
}