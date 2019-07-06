#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int r, c;
    cin >> r >> c;
    int *ar = new int[r];
    int *ac = new int[c];
    int **arr = new int *[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        long min = LONG_MAX;
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
        ar[i] = min;
    }

    for (int i = 0; i < c; i++)
    {
        long max = LONG_MIN;
        for (int j = 0; j < r; j++)
        {
            if (arr[j][i] > max)
            {
                max = arr[j][i];
            }
        }
        ac[i] = max;
    }

    bool found = false;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == ar[i] && arr[i][j] == ac[j]) {
                found = true;
                cout << arr[i][j] << " ";
            }
        }
    }
    if(!found) {
        cout << "No Such Point Exist";
    }

    cout << endl;

    return 0;
}
