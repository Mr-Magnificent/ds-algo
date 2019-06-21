// https://www.geeksforgeeks.org/recursive-c-program-linearly-search-element-given-array/
#include<bits/stdc++.h>
using namespace std;

int find(int* arr, int ele, int index, int size) {
    if(arr[index] == ele) return index;

    if (index == size - 1) return -1;

    return find(arr, ele, index + 1, size);
}

int main(int argc, char** argv) {
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ele = 4;
    cout << "Position of " << ele << " in array is " << find(arr, ele, 0, size) << endl;
}