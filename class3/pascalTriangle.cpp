#include<iostream>
using namespace std;

int fact (int num) {
    if (num == 0) return 1;
    return num * fact(num - 1);
}

int main(int argc, char** argv) {
    int n;
    cout << "Enter pyramid levels ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        int first = 1;
        for(int j = 0; j <= i; j++) {
            cout << first << " ";
            first = first * (i - j) / (j + 1);
        }
        cout << endl;
    }
}