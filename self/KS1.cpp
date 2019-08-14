#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> elements(n);
        for (int i = 0; i < n; i++)
        {
            cin >> elements[i];
        }

        vector<int> ahead(n);
        ahead[0] = elements[0];
        for (int i = 1; i < n; i++)
        {
            ahead[i] = elements[i] ^ ahead[i - 1];
        }

        vector<int> backward(n);
        backward[backward.size() - 1] = elements[elements.size() - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            backward[i] = elements[i] ^ backward[i + 1];
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (ahead[i] == backward[i + 1])
                count++;
        }
        cout << count << endl;
    }
}