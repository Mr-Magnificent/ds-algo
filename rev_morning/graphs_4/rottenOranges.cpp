#include <bits/stdc++.h>
using namespace std;

class Position
{
public:
    int x;
    int y;
    int time;

    Position(int x, int y, int time = 0)
    {
        this->x = x;
        this->y = y;
        this->time = time;
    }
};

int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int FindRottenTime(vector<vector<int>> &arr, queue<Position> &rotten_arr)
{
    int max_time = 0;
    while (!rotten_arr.empty())
    {
        Position rem_rotten = rotten_arr.front();
        rotten_arr.pop();

        int rotten_x = rem_rotten.x;
        int rotten_y = rem_rotten.y;

        if (arr[rotten_x][rotten_y] == 2 && rem_rotten.time != 0)
        {
            continue;
        }

        arr[rotten_x][rotten_y] = 2;

        if (rem_rotten.time > max_time)
        {
            max_time = rem_rotten.time;
        }

        for (int i = 0; i < 4; i++)
        {
            if (rotten_x + dir[i][0] == arr.size() || rotten_x + dir[i][0] < 0)
                continue;
            if (rotten_y + dir[i][1] == arr[0].size() || rotten_y + dir[i][1] < 0)
                continue;
            if (arr[rotten_x + dir[i][0]][rotten_y + dir[i][1]] == 1)
            {
                rotten_arr.push(Position(rotten_x + dir[i][0], rotten_y + dir[i][1], rem_rotten.time + 1));
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return max_time;
}

int main(int argc, char **argv)
{
    int x_size;
    int y_size;
    cin >> x_size >> y_size;
    vector<vector<int>> arr(x_size, vector<int>(y_size));
    queue<Position> rotten_arr;

    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                rotten_arr.push(Position(i, j));
            }
        }
    }

    cout << FindRottenTime(arr, rotten_arr) << endl;
}