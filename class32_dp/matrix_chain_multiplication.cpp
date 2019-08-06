#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(vector<int> &matrix_dim)
{
    vector<vector<int>> strg(matrix_dim.size() - 1, vector<int>(matrix_dim.size() - 1, 0));
    for (int g = 0; g < strg.size(); g++)
    {
        for (int i = 0; i < strg.size() - g; i++)
        {
            int j = i + g;

            // main diagonal
            if (g == 0)
            {
                strg[i][j] = 0;
            }
            // when there is multiplication of just two matrices
            else if (g == 1)
            {
                int row1 = matrix_dim[i];
                int col1 = matrix_dim[i + 1];
                int col2 = matrix_dim[j + 1];
                strg[i][j] = row1 * col1 * col2;
            }
            // for other cases
            else
            {
                int min = INT_MAX;
                int costOverall = matrix_dim[i] * matrix_dim[j + 1];

                for (int k = 0; k < g; k++)
                {
                    int left = strg[i][i + k];
                    int right = strg[i + 1 + k][j];
                    if ((left + right) < min)
                    {
                        min = left + right;
                        strg[i][j] = min + costOverall * matrix_dim[k  + 1];
                    }
                }
            }
        }
    }

    for (int i = 0; i < strg.size(); i++) {
        for (int j = 0; j < strg[0].size(); j++) {
            printf("%7d ", strg[i][j]);
        }
        cout << endl;
    }
    // cout << strg[0][strg.size() - 1];
    return strg[0][strg.size() - 1];
}

int main(int argc, char **argv)
{
    vector<int> matrix_dim = {10, 20, 30, 40, 50, 60};
    auto start = chrono::high_resolution_clock::now();
    cout << MatrixChainMultiplication(matrix_dim) << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Time take " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}