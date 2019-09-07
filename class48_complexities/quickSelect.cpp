#include <bits/stdc++.h>
using namespace std;

int quickSelect(vector<int> &arr, int lo, int hi)
{
    int i = 0;
    int j = 0;
    for (; i < hi;)
    {
        if (arr[i] <= arr[hi])
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    swap(arr[j], arr[hi]);
    return j;
}

int partitioning(vector<int> &arr, int lo, int hi, int indToFind)
{
    if (lo == hi)
    {
        return lo;
    }
    int ind = quickSelect(arr, lo, hi);
    if (ind == indToFind)
    {
        return ind;
    }
    if (ind < indToFind)
    {
        return partitioning(arr, ind + 1, hi, indToFind);
    }
    else
    {
        return partitioning(arr, lo, ind - 1, indToFind);
    }
}

void quicksort(vector<int> &arr, int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }

    int ind = quickSelect(arr, lo, hi);
    quicksort(arr, lo, ind - 1);
    quicksort(arr, ind + 1, hi);
}

int main(int argc, char **argv)
{
    vector<int> arr = {1233, 234, 234, 123, 5, 43, 53, 5234, 21, 213, 132, 3213, 34};
    int x = 9;
    partitioning(arr, 0, arr.size() - 1, x);
    cout << "Item at " << x << "th indx:\t" << arr[x] << endl;
    cout << "Array after quickselect:\t";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    quicksort(arr, 0, arr.size() - 1);

    cout << "Array after quicksort:\t\t";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}