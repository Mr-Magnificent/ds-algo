#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long m, n;
        cin >> m >> n;
        vector<bool> strg(n);

        for (int i = 2; i * i <= n; i++)
        {
            for (int j = 0; j < n; j += i)
            {
                strg[j] = true;
            }
        }
        
        for (int i = m; i < strg.size() - 6; i++)
        {
            if (!strg[i] && !strg[i + 6])
            {
                cout << i << " " << i + 6 << " ";
            }
        }
    }
    cout << endl;
    return 0;
}