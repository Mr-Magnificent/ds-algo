#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int arr[3][5] = {{1, 2, 3, 4, 5}, {11, 12, 13, 14, 15}, {21, 22, 23, 24, 25}};
    // int r = arr.length;
    // ;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    int rl1 = 0, rl2 = 2, cl1 = 0, cl2 = 4;
    int dir = 0;
    // 0 down
    // 1 right
    // 2 up
    // 3 left
    int r = 0, c = 0;
    while ((rl1 <= rl2) || (cl1 <= cl2))
    {
        switch (dir)
        {
        case 0:
            for (int i = rl1; i <= rl2; i++)
            {
                cout << arr[i][cl1] << " ";
            }
            cl1++;
            dir = 1;
            break;
        case 1:
            for (int i = cl1; i <= cl2; i++)
            {
                cout << arr[rl2][i] << " ";
            }
            rl2--;
            dir = 2;
            // rl2--;
            break;
        case 2:
            for (int i = rl2; i >= rl1; i--)
            {
                cout << arr[i][cl2] << " ";
            }
            dir = 3;
            cl2--;
            // rl1--;
            break;
        case 3:
            for (int i = cl2; i >= cl1; i--)
            {
                cout << arr[rl1][i] << " ";
            }
            dir = 0;
            rl1++;
            // cl1--;
            break;
        }
    }
    cout << endl;
}