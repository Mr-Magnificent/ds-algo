// https://leetcode.com/problems/k-inverse-pairs-array/
#include <bits/stdc++.h>
using namespace std;

int kReverse(int n, int k)
{
    vector<vector<int>> strg(k + 1, vector<int>(n));
    for (int i = 0; i < strg[0].size(); i++)
    {
        strg[0][i] = 1;
    }

    for (int i = 1; i < strg[0].size(); i++)
    {
        for (int j = 1; j < strg.size(); j++)
        {
            if (i < j && j <= k)
            {
                strg[j][i] = 0;
            }
            else
            {
                strg[j][i] = ((strg[j][i - 1] % 1000000007) + (strg[j - 1][i] % 1000000007)) % 1000000007;
            }
        }
    }

    for (int i = 0; i < strg.size(); i++)
    {
        for (int j = 0; j < strg[0].size(); j++)
        {
            cout << strg[i][j] << "\t";
        }
        cout << endl;
    }
    return strg[strg.size() - 1][strg[0].size() - 1];
}

int main(int argc, char **argv)
{
    cout << argv[1] << " " << argv[2] << endl;
    cout << kReverse(stoi(argv[1]), stoi(argv[2])) << endl;
}