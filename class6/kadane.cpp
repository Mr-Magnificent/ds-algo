#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int arr[] = {1,2,3,6,-1,2,23,-2,1234};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *partialSum = new int[len] {0};
    int sum = 0;
    int begin = -1, end = -1;
    for(int i = 0; i < len; i++) {
        int temp = sum + arr[i];
        if(temp < 0) {
            sum = 0;
            partialSum[i] = temp;
            continue;
        }
        partialSum[i] = temp;
        sum = temp;
    }

    // for(int i = 0; i < len; i++) cout << partialSum[i] << " ";

    int max = INT_MIN;
    bool found = false;
    for(int i = len - 1; i >= 0; i--) {
        if(partialSum[i] > max) {
            max = partialSum[i];
            end = i;
            found = true;
        }
        if (partialSum[i] >= 0 && found) {
            begin = i;
        } else if (partialSum[i] < 0 && found) {
            begin = i + 1;
            cout << partialSum[i] << " ";
            found = false;
        } else if (i == 0 && found) {
            begin = 0;
        }
    }
    cout << begin << " " << end << " " << max << endl;
}