#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void daycount(int *arr, int start, int end)
{
    if (start == end)
    {
        return;
    }
    int ind = start % 7;
    arr[ind]++;
    daycount(arr, start + 1, end);
}

// "mon", "tues", "wed", "thurs", "fri", "sat" or "sun",

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int *arr = new int[7]{0};
        int days;
        string firday;
        cin >> days >> firday;
        daycount(arr, 0, days);
        if (firday == "mon")
        {
            for (int i = 0; i < 7; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (firday == "tues")
        {
            for (int i = 6, ind = 0; ind < 7; ind++, i = (i + 1) % 7)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (firday == "wed")
        {
            for (int i = 5, ind = 0; ind < 7; ind++, i = (i + 1) % 7)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (firday == "thurs")
        {
            for (int i = 4, ind = 0; ind < 7; ind++, i = (i + 1) % 7)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (firday == "fri")
        {
            for (int i = 3, ind = 0; ind < 7; ind++, i = (i + 1) % 7)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (firday == "sat")
        {
            for (int i = 2, ind = 0; ind < 7; ind++, i = (i + 1) % 7)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (firday == "sun")
        {
            for (int i = 1, ind = 0; ind < 7; ind++, i = (i + 1) % 7)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        delete arr;
    }
    return 0;
}
