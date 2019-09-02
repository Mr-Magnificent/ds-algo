#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    int sum = 0;
    int prod = x;
    for (int i = n; i >= 1; i--)
    {
        sum += i * prod;
        prod *= x;
    }
    return sum;
}

int main(int argc, char **argv)
{
    int i = 2;
    int j = 3;

    cout << power(i, j) << endl;
}