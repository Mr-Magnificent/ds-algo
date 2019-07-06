#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void display(string &s, int i)
{
    if (i == s.length())
    {
        return;
    }
    cout << s[i];
    display(s, i + 1);
    return;
}

string replace(string s, int i)
{
    if (i == s.length())
    {
        return "";
    }
    if (s[i] == s[i + 1])
    {
        string res = replace(s, i + 1);
        string temp (1, s[i]);
        // cout << (temp + "*");
        return (temp + "*" + res);
    }
    string res = replace(s, i + 1);
    return (s[i] + res);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    int n;
    cin >> s >> n;
    s = replace(s, 0);
    // cout << s[n] << endl;
    display(s, 0);
    cout << endl;
    return 0;
}
