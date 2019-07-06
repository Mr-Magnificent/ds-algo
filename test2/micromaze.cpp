#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dir1[] = {0, 0, 1, -1};
int dir2[] = {1, -1, 0, 0};

bool visit(int **arr, int limi, int limj, int i, int j, int previ, int prevj) {
    if(i == limi && j == limj) {
        // cout << "Yes\n";
        return true;
    }
    for(int t = 0; t < 4; t++) {
        int d1 = dir1[t];
        int d2 = dir2[t];
        if((i + d1) == previ && (j + d2) == prevj) continue;
        if ((i + d1) >= 0 && (i + d1) <= (limi) && (j + d2) >= 0 && (j + d2) <= limj && arr[i + d1][j + d2] == 1) {
            bool temp = visit(arr, limi, limj, i + d1, j + d2, i, j);
            if (temp == true) return true;
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bool found = visit(arr, n - 1, m - 1, 0, 0, -1, -1);
    if(found) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
