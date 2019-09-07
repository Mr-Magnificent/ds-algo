#include <bits/stdc++.h>
using namespace std;

int inversion = 0;

vector<int> merge(vector<int> &fh, vector<int> &sh) {
    vector<int> fsa(fh.size() + sh.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < fh.size() && j < sh.size()) {
        if (fh[i] < sh[j]) {
            fsa[k++] = fh[i++];
        } else {
            fsa[k++] = sh[j++];
            inversion += fh.size() - i;
        }
    }

    
    while (i < fh.size()) {
        fsa[k++] = fh[i++];
    }

    while (j < sh.size()) {
        fsa[k++] = sh[j++];
    }

    return fsa;
}

vector<int> mergesort(vector<int> &arr, int low, int hi) {
    if (low == hi) {
        vector<int> temp;
        temp.push_back(arr[low]);
        return temp;
    }

    int mid = (low + hi) / 2;
    vector<int> fh = mergesort(arr, low, mid);
    vector<int> sh = mergesort(arr, mid + 1, hi);
    vector<int> fsa = merge(fh, sh);

    return fsa;
}

int main(int argc, char **argv)
{
    vector<int> arr = {2, 5, 1, 8, 6, 3, 7, 4};
    vector<int> sorted = mergesort(arr, 0, arr.size() - 1);
    for (int x : sorted) {
        cout << x << " ";
    }
    cout << endl;
    cout << inversion;
    cout << endl;
}