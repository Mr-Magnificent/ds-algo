#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{
        {1 , 2 , 3 , 4 , 5 },
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35},
        {41, 42, 43, 44, 45},
    };
    int i = 0;
    int j = 0;
    bool zig = true;
    int tot = v.size();
    int act = tot - 1;
    bool increment = true;
    do
    {

        cout << v[i][j] << " ";

        if ((j == 0 || i == act) && zig == false)
        {
            if (increment)
                i++;
            else
                j++;
            zig = true;
        }
        else if ((i == 0 || j == act) && zig == true)
        {
            if (increment)
                j++;
            else
                i++;
            zig = false;
        }
        else if (zig)
        {
            i--;
            j++;
        }
        else
        {
            i++;
            j--;
        }

        if ((i + j) == act && increment)
        {
            increment = false;
        }
    } while (i != act || j != act);
    cout << v[act][act];
    
    cout << endl;
    return 0;
}
