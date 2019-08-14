#include <bits/stdc++.h>
using namespace std;

int FindWeight(vector<int> &nodes, vector<int> &freq)
{
    vector<vector<int>> strg(nodes.size(), vector<int>(nodes.size(), 0));

    vector<int> freqPartialSum(nodes.size(), 0);
    for (int i = 0, ps = 0; i < freq.size(); i++)
    {
        ps += freq[i];
        freqPartialSum[i] = ps;
    }

    for (int g = 0; g < nodes.size(); g++)
    {
        for (int i = 0; i < nodes.size() - g; i++)
        {
            int j = i + g;
            if (g == 0)
            {
                strg[i][j] = freq[i];
            }
            else if (g == 1)
            {
                strg[i][j] = min(strg[i][j - 1] + 2 * strg[i + 1][j], 2 * strg[i][j - 1] + strg[i + 1][j]);
            }
            else
            {
                int min_val = INT_MAX;
                for (int k = 0; k <= g; k++) {
                    int left = (k > 0) ? strg[i][i + k - 1] : 0;
                    int right = (k != g) ? strg[i + 1 + k][j] : 0;

                    min_val = min(min_val, (left + right));
                }
                
                strg[i][j] = min_val + freqPartialSum[j];
                if (i > 0) {
                    strg[i][j] -= freqPartialSum[i - 1];
                }
            }
        }
    }

    for (int i = 0; i < strg.size(); i++)
    {
        for (int j = 0; j < strg[0].size(); j++)
        {
            printf("%3d ", strg[i][j]);
        }
        cout << endl;
    }

    return strg[0][strg.size() - 1];
}

int main(int argc, char **argv)
{
    vector<int> nodes({10, 20, 30, 40, 50, 60, 70});
    vector<int> freq({ 2, 1, 4, 1, 1, 3, 5 });
    FindWeight(nodes, freq);
}
