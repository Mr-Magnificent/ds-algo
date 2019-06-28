#include<bits/stdc++.h>
using namespace std;

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp; 
}

void reverse(char* arr, int l, int r) {
    while(l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void rotate(char* arr, int size, int k) {
    k %= size;
    k = (k < 0)? size + k: k;
    reverse(arr, 0, size - k - 1);
    reverse(arr, size - k, size - 1);
    reverse(arr, 0 , size - 1);
}

void display(char* arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    char arr[] = {'a', 'b', 'c', 'd' , 'e', 'f', 'g'};
    int rot;
    cout << "Enter the rotation\n";
    cin >> rot;
    int size = (sizeof(arr) / sizeof(arr[0]));
    rotate(arr, size, rot);
    display(arr, size);
}