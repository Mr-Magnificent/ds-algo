#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int temp = n;
    long val = 0;
    for (int i = 1; temp != 0; i++) {
        int temp2 = temp % 10;
        val += (i) * pow(10, temp2);
        temp /= 10;
    }
    cout << val / 10 << endl;
}