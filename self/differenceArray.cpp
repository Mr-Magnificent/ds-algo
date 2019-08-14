#include <bits/stdc++.h>
using namespace std;

void setDifferenceArray(vector<long> &df_arr, const vector<unsigned long> &rad_arr)
{
    // Range query for all numbers
    for (int i = 0; i < rad_arr.size(); i++)
    {
        int left = max(0l, i - (long)rad_arr[i]);
        int right = min(rad_arr.size() - 1, i + (unsigned long)rad_arr[i]);
        cout << rad_arr[i] << "->" << left << "--" << right << endl;

        df_arr[left] += 1;
        df_arr[right + 1] -= 1;
    }
}

int main(int argc, char **argv)
{
    vector<unsigned long> rad_arr({1, 2, 3, 4, 5});
    vector<long> df_arr(rad_arr.size() + 1, 0);
    setDifferenceArray(df_arr, rad_arr);

    rad_arr[0] = df_arr[0];

    for (int i = 1; i < rad_arr.size(); i++)
    {
        rad_arr[i] = df_arr[i] + rad_arr[i - 1];
    }

    for (int i = 0; i < rad_arr.size(); i++)
    {
        cout << rad_arr[i] << " ";
    }
    cout << endl;
}