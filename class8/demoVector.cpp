#include<iostream>
#include<vector>
using namespace std;

bool isOdd(int n) {
    if(n % 2) {
        return true;
    } else {
        return false;
    }
}

vector<int> check (int n) {
    vector<int> res;
    cout << typeid(res.size()).name();
    for(int i = 0; i < n; i++) {
        bool flag = isOdd(i);
        if(flag) {
            res.push_back(i);
        }
    }
    return res;
}

int main(int argc, char** argv) {
    int n;
    cout << "Please enter count of elements ";
    cin >> n;
    vector<int> v = check(n);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}