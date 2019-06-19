//reviewed
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int e1s = 0;
    int e1e = 5;
    int e2s = 10;
    int e2e = 12;
    if (e1e < e2s || e1s > e2e) {
        cout << "No Overlap\n";
    } else if ((e1s >= e2s && e1e <= e2e) || e1s < e2s && e1e > e2e) {
        cout << "Full Overlap\n";
    } else {
        cout << "Partial Overlap\n";
    }
}