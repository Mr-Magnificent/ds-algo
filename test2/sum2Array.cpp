#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sum(int *n1, int *n2, int ind1, int ind2, int carry)
{
    if (ind1 < 0 && ind2 < 0)
    {
        if (carry)
            cout << carry << " ";
        return;
    }
    int val = carry;
    if (ind1 >= 0)
    {
        val += n1[ind1];
    }
    if (ind2 >= 0)
    {
        val += n2[ind2];
    }
    sum(n1, n2, ind1 - 1, ind2 - 1, val / 10);
    cout << val % 10 << " ";
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n;
    int *n1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> n1[i];
    }
    cin >> m;
    int *n2 = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> n2[i];
    }
    sum(n1, n2, n - 1, m - 1, 0);
    cout << endl;
    return 0;
}
