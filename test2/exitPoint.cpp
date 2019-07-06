#include<iostream>
#include<vector>
using namespace std;

    void exitPoint(vector<vector<int>>& arr) {
        // Write your code only here.
        // 0 right
        // 1 down
        // 2 right
        // 3 up
        int i = 0;
        int j = 0;
        int dir1lim = arr.length();
        int dir2lim = arr[0].length() - 1;
        dir = 0;
        while (i >= 0 && i < dir1lim && j >= 0 && j < dir2lim) {

        }
    }



    // This is a functional problem.
    // Input is managed for you.
    // Don't change main, write your code in the function below

    int main() {
        int r;
        cin>>r;
        int c;
      	cin >> c;
        vector<vector<int>> arr(r,vector<int>(r,0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin>>arr[i][j];
            }

        }
        exitPoint(arr);
    }