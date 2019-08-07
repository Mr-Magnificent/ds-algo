#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int CoinGame(vector<int> &coins, vector<vector<int>> &strg, int i, int j)
{
    if (i == j)
    {
        return coins[i];
    }
    if (i > j)
    {
        return 0;
    }
    if (strg[i][j] != 0)
    {
        return strg[i][j];
    }

    // I choose first coin
    // -> then Player chooses second coin
    int val1 = CoinGame(coins, strg, i + 2, j);
    // -> or player chooses last coin
    int val2 = CoinGame(coins, strg, i + 1, j - 1);

    // Player tries to maximize his score by taking max of val1 and val2
    // I am left with the minimum of val1 and val2
    int ret1 = min(val1, val2);

    // I choose second coin
    // -> then Player chooses first coin
    int val3 = CoinGame(coins, strg, i + 1, j - 1);
    // -> or Player chooses second last coin
    int val4 = CoinGame(coins, strg, i, j - 2);

    // Player tries to maximize his score by taking max of val3 and val4
    // I am left with the minimum of val3 and val4
    int ret2 = min(val3, val4);

    // I try to maximize my score by choosing that coin which gives me best solution
    // I take maximum of coin 1 + ret1 and coin2 + ret2
    int bestTotal = max(coins[i] + ret1, coins[j] + ret2);
    strg[i][j] = bestTotal;
    return bestTotal;
}

int main(int argc, char **argv)
{
    vector<int> coins({20, 30, 2, 2, 2, 10});
    vector<vector<int>> strg(coins.size(), vector<int>(coins.size(), 0));
    auto start = chrono::high_resolution_clock::now();
    cout << CoinGame(coins, strg, 0, coins.size() - 1) << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Time taken " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
}
