#include <bits/stdc++.h>
using namespace std;

void setDifferenceArray(vector<long> &df_arr, const vector<unsigned long> &rad_arr)
{
    // Range query for all numbers
    for (int i = 0; i < df_arr.size(); i++)
    {
        int left = max(0l, i - (long)rad_arr[i]);

        int right = min(rad_arr.size() - 1, i + (unsigned long)rad_arr[i]);

        df_arr[left] += 1;
        df_arr[right + 1] -= 1;
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
        vector<unsigned long> radiation;
        vector<unsigned long> hel;
        int n;
        cin >> n;
        vector<long> difference_array(n, 0);

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            radiation.push_back(temp);
        }

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            hel.push_back(temp);
        }

        // create difference array
        setDifferenceArray(difference_array, radiation);

        // Create resultant array after update
        radiation[0] = difference_array[0];

        for (int i = 1; i < n; i++)
        {
            radiation[i] = difference_array[i] + radiation[i - 1];
        }

        for (int i = 0; i < radiation.size(); i++) {
            cout << radiation[i] << " ";
        }
        cout << endl;

        sort(radiation.begin(), radiation.end());
        sort(hel.begin(), hel.end());

        bool flag = false;
        for (int i = 0; i < radiation.size(); i++)
        {
            if (hel[i] != radiation[i])
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