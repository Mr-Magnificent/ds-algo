#include <iostream>
using namespace std;

void sieveOfErosthenes(int n) {
    bool * arr = new bool[n];
    for (int i = 2; i * i < n; i++) {
        if (arr[i] == false) {
            for (int j = i * i; j <= n; j += i) {
                arr[j] = true;
            }
        }
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] == false) {
            cout << i << " ";
        }
    }
}

int main(int argc, char **argv) {
    sieveOfErosthenes(30);
    cout << endl;
}