#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *goals = new int[n];
        int *pen = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> goals[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pen[i];
        }
        int max_value = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = goals[i] * 2 - pen[i];
            max_value = max(max_value, temp);
        }
        cout << max_value * 10 << "\n";
    }
}