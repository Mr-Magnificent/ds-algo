#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    // [5] {{11,12,13,14,15}, {21,22,23,24,25}, {31,32,33,34,35}};
    int **arr = new int*[3];
    // for(int i  = 0; i < 3; i++) {
    //     arr[i] = new int[5];
    // }
    arr[0] = new int[5] {11,12,13,14,15};
    arr[1] = new int[5] {21,22,23,24,25};
    arr[2] = new int[5] {31,32,33,34,35};

    for(int j = 0; j < 5; j++) {
        if(j % 2 == 0) {
            for(int i = 0; i < 3; i++) {
                cout << arr[i][j] << " ";
            }
        } else {
            for (int i = 2; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}