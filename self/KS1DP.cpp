#include <bits/stdc++.h>
using namespace std;

int findXOR(vector<int> &nums, vector<vector<int>> &strg)
{
    int count = 0;
    vector<int> xor_arr(nums.size() + 1);
    for (int i = 1; i < xor_arr.size(); i++)
    {
        xor_arr[i] = xor_arr[i - 1] ^ nums[i - 1];
    }

    for (int g = 0; g < strg.size(); g++)
    {
        for (int i = 0; i < strg.size() - g; i++)
        {
            int j = i + g;
            if (g == 0)
            {
                strg[i][j] = nums[i];
            }
            else if (g == 1)
            {
                strg[i][j] = strg[i + 1][j] ^ strg[i][j - 1];
                if (nums[j] == nums[j - 1])
                {
                    count++;
                }
            }
            else
            {
                for (int k = 0; k < g; k++)
                {
                    int left = strg[i][i + k];
                    int right = strg[i + k + 1][j];

                    if (left == right)
                    {
                        count++;
                    }
                }
                strg[i][j] = xor_arr[j + 1] ^ xor_arr[i];
            }
        }
    }

    return count;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<vector<int>> strg(n, vector<int>(n, 0));
        cout << findXOR(nums, strg) << endl;
    }
}