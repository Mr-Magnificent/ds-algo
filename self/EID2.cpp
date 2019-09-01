// https://www.codechef.com/LTIME75B/problems/EID2
#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortIt(vector<int> &age, vector<int> &mon)
{
    if (age[1] < age[0])
    {
        swap(age[1], age[0]);
        swap(mon[1], mon[0]);
    }

    if (age[2] < age[0])
    {
        swap(age[2], age[0]);
        swap(mon[2], mon[0]);
    }

    if (age[2] < age[1])
    {
        swap(age[2], age[1]);
        swap(mon[2], mon[1]);
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> age(3);
        vector<int> mon(3);

        for (int i = 0; i < 3; i++)
        {
            cin >> age[i];
        }

        for (int i = 0; i < 3; i++)
        {
            cin >> mon[i];
        }

        sortIt(age, mon);
        bool output = false;
        for (int i = 0; i < 2; i++)
        {
            if (age[i] == age[i + 1] && mon[i] != mon[i + 1])
            {
                cout << "NOT FAIR\n";
                output = true;
                break;
            }
            else if (age[i] < age[i + 1] && mon[i] >= mon[i + 1])
            {
                cout << "NOT FAIR\n";
                output = true;
                break;
            }
        }
        if (!output)
        {
            cout << "FAIR\n";
        }
    }
}