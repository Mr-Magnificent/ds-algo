#include <bits/stdc++.h>
using namespace std;

char getHighestFreqChar(vector<char> &arr) {
    vector<int> fm(26);
    int maxInd = 0;

    for (char x: arr) {
        int val = (int)x - 'a';
        fm[val]++;

        if (fm[val] > fm[maxInd]) {
            maxInd = val;
        }
    }

    return (char)(maxInd + 'a');
}

int main(int argc, char **argv)
{
    vector<char> arr = {'a', 'b', 's', 'a', 'u', 'r', 'u', 'p', 'y',
                        'z', 'r', 'a', 'w', 'q'};

    cout << getHighestFreqChar(arr) << endl;
}