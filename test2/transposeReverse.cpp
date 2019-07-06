#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(int N, vector<vector<int>> &mat)
{
    //you need to write this function only
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;
        while (left < right)
        {
            int temp = mat[left][i];
            mat[left][i] = mat[right][i];
            mat[right][i] = temp;
            left++;
            right--;
        }
    }
}

static void displayMatrix(int N, vector<vector<int>> &mat)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";

        cout << endl;
    }
    cout << endl;
}

int main()
{
    int r;
    cin >> r;
    int c = r;
    vector<vector<int>> arr(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int n = arr.size();
    rotateMatrix(n, arr);
    displayMatrix(n, arr);
    return 0;
}