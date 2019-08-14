#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> &price, vector<int> &strg)
{
    strg[0] = 0;
    strg[1] = price[0];
    for (int i = 2; i < strg.size(); i++)
    {
        int max_val = price[i];
        for (int j = i - 1; j >= i / 2; j--)
        {
            max_val = max(max_val, (strg[j] + strg[i - j]));
        }
        strg[i] = max_val;
    }

    for (int i = 0; i < strg.size(); i++)
    {
        cout << strg[i] << " ";
    }
    cout << endl;
    
    return strg[strg.size() - 1];
}

int main(int argc, char **argv)
{
    vector<int> price({0, 3, 5, 6, 15, 10, 25, 12, 24});
    vector<int> strg(price.size() + 1, 0);
    cout << rodCutting(price, strg) << endl;
}