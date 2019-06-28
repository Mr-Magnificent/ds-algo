#include <bits/stdc++.h>
using namespace std;

void swap(int* arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void reverse(int* arr, int n) {
    int left = 0;
    int right = n - 1;
    while(left < right) {

        swap(arr, left, right);

        left++;
        right--;
    }
}

void display(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** agrv) {
    int arr[5] = {1,2,3,4,5};
    int* dy = new int[5] {1,2,3,4,5};
    int x = 10;
    int* p = &x;
    cout << "Size of pointer to integer " << sizeof(p) << endl;
    cout << "Size of pointer to heap array " << sizeof(dy) << endl;
    cout << "Size of array in stack " << sizeof(arr) << endl;
    cout << "Size of integer " << &main << endl;
    cout << sizeof(dy) << endl;
    cout << sizeof(arr) << endl;
    // cout << *arr << " " << arr[0] << endl;
    cout << &arr << " " << &arr[0] << endl;
    cout << &dy << " " << &dy[0] << endl;

    reverse(arr, 5);
    display(arr, 5);
    }