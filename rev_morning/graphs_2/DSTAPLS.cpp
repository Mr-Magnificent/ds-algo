#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long int n, k;
        cin >> n >> k;
        if ((n / k) == n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}