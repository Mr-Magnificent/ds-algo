#include <bits/stdc++.h>
using namespace std;

int maxLIS(vector<int> &arr, vector<int> &strg)
{
    strg[0] = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        int max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i] && strg[j] > max)
            {
                max = strg[j];
            }
        }
        strg[i] = max + 1;
    }
    int max = 0;
    for (int i = 0; i < strg.size(); i++)
    {
        if (strg[i] > max)
        {
            max = strg[i];
        }
    }
    return max;
}

void minLIS(string sol, int val, int end, vector<int> &strg, vector<int> &arr)
{
    for (int i = strg.size() - 1; i >= 0; i--)
    {
        if (strg[i] == val - 1) {
            minLIS()
        }
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 21, 9, 33, 22, 50, 41, 60, 80, 7};
    vector<int> strg(arr.size());
    int min = maxLIS(arr, strg);
    cout << min;
}