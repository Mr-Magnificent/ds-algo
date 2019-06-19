#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int t;
    cout << "Please enter a number\n";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter the number\n";
        cin >> n;
        bool flag = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cout << n << " is not prime\n";
                flag = 1;
                break;
            }
        }
        if(flag != 1) cout << n << " is prime\n";
        cout << endl;
    }
}