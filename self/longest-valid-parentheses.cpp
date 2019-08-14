// https://leetcode.com/problems/longest-valid-parentheses/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int longestValidParentheses(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        vector<vector<int>> strg(s.length(), vector<int>(s.length(), 0));
        for (int g = 0; g < s.length(); g++)
        {
            for (int i = 0; i < strg.size() - g; i++)
            {
                int j = i + g;
                if (g == 0) {
                    strg[i][j] = 0;
                }
                else if (g == 1)
                {
                    if (s[i] == '(' && s[j] == ')')
                    {
                        strg[i][j] = 2;
                    }
                }
                else
                {
                    if (strg[i + 1][j - 1] == strg[i + 1][j] && strg[i + 1][j] == strg[i][j - 1] && strg[i + 1][j - 1] != 0) {
                        strg[i][j] = strg[i + 1][j - 1] + 2;
                        continue;
                    }
                    int maximum_valid = 0;
                    for (int k = 0; k < g; k++)
                    {
                        int left = strg[i][i + k];
                        int right = strg[i + 1 + k][j];

                        int local_valid = max(left, right); 
                        if (maximum_valid < local_valid) {
                            maximum_valid = local_valid;
                        }
                    }
                    strg[i][j] = maximum_valid;
                }
            }
        }

        for (int i = 0; i < strg.size(); i++)
        {
            for (int j = 0; j < strg[0].size(); j++)
            {
                cout << strg[i][j] << " ";
            }
            cout << endl;
        }
        
        return strg[0][strg[0].size() - 1];
    }
};

int main(int argc, char **argv)
{
    string s;
    cin >> s;
    cout << Solution::longestValidParentheses(s) << endl;
}
