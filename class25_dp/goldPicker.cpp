#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Position
{
public:
    Position(int x, int y, string s): x(x), y(y), sol(s) {
    }

    int x;
    int y;
    string sol;
};

void printPath(int i, vector<vector<int>> &sol)
{
    queue<Position> q;
    q.push()
}

int minSol(vector<vector<int>> &sol, vector<vector<int>> &arr)
{
    int j = sol.size() - 2;
    while (j >= 0)
    {
        for (int i = 0; i < sol.size(); i++)
        {
            if (i > 0 && i < sol.size() - 1)
            {
                if (arr[i - 1][j + 1] > arr[i][j + 1])
                    sol[i][j] = max(sol[i - 1][j + 1], sol[i + 1][j + 1]) + arr[i][j];
                else
                    sol[i][j] = max(sol[i][j + 1], sol[i + 1][j + 1]) + arr[i][j];
            }
            else if (i > 0)
            {
                sol[i][j] = max(sol[i - 1][j + 1], sol[i][j + 1]) + arr[i][j];
            }
            else
            {
                sol[i][j] = max(sol[i][j + 1], sol[i + 1][j + 1]) + arr[i][j];
            }
        }
        j--;
    }

    int max = INT_MIN;
    for (int i = 0; i < sol.size(); i++)
    {
        if (sol[i][0] > max)
        {
            max = sol[i][0];
        }
    }
    // cout << max << endl;
    return max;
}

int main(int argc, char **argv)
{
    vector<vector<int>> arr = {{1, 5, 1, 0, 3},
                               {1, 4, 0, 2, 3},
                               {4, 0, 1, 3, 2},
                               {2, 4, 0, 4, 1},
                               {1, 2, 3, 2, 0}};

    vector<vector<int>> sol = {
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 2},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};

    int max = INT_MIN;

    int temp = minSol(sol, arr);
    cout << temp << endl;
}