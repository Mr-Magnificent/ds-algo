#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string hiPep(string s, int i) {
    if (i >= s.length()) {
        return "";
    }
    if(s[i] == 'h' && s[i + 1] == 'i') {
        string res = hiPep(s, i + 2);
        return ("pep" + res);
    }
    string temp(1, s[i]);
    string res = hiPep(s, i + 1);
    return temp + res;
}

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

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    int n;
    cin >> s >> n;
    string res = hiPep(s, 0);
    cout << res[n] << endl;
    display(res, 0);
    cout << endl;
    return 0;
}
