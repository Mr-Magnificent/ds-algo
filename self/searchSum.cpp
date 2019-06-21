#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int n;
    int size;
    cout << "Enter the number of element in the array: ";
    cin >> size;
    cout << "Enter the elements of the array\n";
    for(int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    cout << "Enter the element to search: ";
    cin >> n;

    unordered_set<int> s;
    bool found = false;

    for(auto it: s) {
        auto temp = s.find(n - it);
        if (temp != s.end() && *temp != it) {
            found = true;
        }
    }

    if (found) cout << "Elements found with their sum\n";
    else cout << "Elements not found\n";
}