#include<iostream>
using namespace std;

int** getValues(int r, int c) {
    int** arr = new int* [r];
    for(int i = 0; i < r; i++) {
        arr[i] = new int[c];
        for (int j = 0; j < c; j++) {
            cout << "Enter the element in cell [" << i << " " << j << "] ";
            cin >> arr[i][j];
        }
    }
    return arr;
}

void display(int** arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0 ; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {
    int r;
    int c;
    cout << "Enter the rows of the array ";
    cin >> r;
    cout << "\nEnter the columns of the array ";
    cin >> c;
    int** arr = getValues(r, c);
    display(arr, r, c);
}