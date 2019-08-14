#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                count++;
        }
        if (count % 2 == 1)
        {
            cout << "WIN\n";
        }
        else
        {
            cout << "LOSE\n";
        }
    }
}