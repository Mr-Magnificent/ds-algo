#include<iostream>
using namespace std;

void zigzag(int n, bool odd, int orig) {
    if (n == 1) {
        cout << " 1 ";
        return;
    } 
    else if (n == 2) {
        cout << " 2 ";
        return;
    };
    if(odd) {
        int temp = n;
        if(n % 2 == 0) temp -= 1;
        zigzag(temp - 2, odd, orig);
        cout << " " << temp << " ";
        if(n == orig || n == orig - 1) {
            odd = false;
        }
    }
    if(!odd) {
        if(n % 2 == 1) n -= 1;
        zigzag(n - 2, odd, orig);
        cout << " " << n << " ";
    }
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    bool odd = true;
    zigzag(n, odd, n);
}