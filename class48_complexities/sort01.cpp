#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

void sort01(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }
}

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void sort012(vector<int> &arr)
{
    for (int i = 0, j = 0, k = arr.size() - 1; i != k + 1;)
    {
        if (arr[i] == 1)
        {
            i++;
        }
        else if (arr[i] == 0)
        {
            swap(arr,i, j);
            i++;
            j++;
        }
        else if (arr[i] == 2){
            swap(arr, i, k);
            k--;
        }
    }
}

// void sortHiLo()

int main(int argc, char **argv)
{
    // vector<int> arr1 = {0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1};
    vector<int> arr2 = {0, 1, 2, 1, 0, 1, 1, 2, 0, 1, 2, 1, 0, 0, 1, 0, 1};
    // sort01(arr1);
    sort012(arr2);
    // display(arr1);
    display(arr2);
}