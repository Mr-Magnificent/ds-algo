#include <bits/stdc++.h>
using namespace std;

void DifferenceArray(vector<int> &caves, vector<int> &radiation)
{
    for (int i = 0; i < radiation.size(); i++)
    {
        int left = ((i - radiation[i]) < 0) ? 0 : (i - radiation[i]);
        int right = ((i + radiation[i]) > radiation.size() - 1) ? radiation.size() - 1 : (i + radiation[i]);

        caves[left] += 1;
        if (right < radiation.size() - 1)
            caves[right + 1] -= 1;
    }

    for (int i = 1; i < caves.size(); i++)
    {
        caves[i] = caves[i] + caves[i - 1];
    }
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
        vector<int> radiation(n);
        vector<int> zombies(n);
        for (int i = 0; i < n; i++)
        {
            cin >> radiation[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> zombies[i];
        }

        vector<int> caves(n, 0);
        DifferenceArray(caves, radiation);
        // for (int i = 0; i < radiation.size(); i++)
        // {
        //     int left = ((i - radiation[i]) < 0) ? 0 : (i - radiation[i]);
        //     int right = ((i + radiation[i]) > radiation.size() - 1) ? radiation.size() - 1 : (i + radiation[i]);

        //     for (int i = left; i <= right; i++)
        //     {
        //         caves[i]++;
        //     }
        // }

        sort(caves.begin(), caves.end());
        sort(zombies.begin(), zombies.end());

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (caves[i] != zombies[i])
            {
                cout << "NO\n";
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            cout << "YES\n";
        }
    }
}