#include<iostream>
#include<vector>
using namespace std;

void filter(vector<int>& v) {
    for(int i = v.size() - 1; i >= 0; i--) {
        if(v[i] > 50)
        {
            v.erase(v.begin() + i);
        }
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    vector<int> v {23,4,2,41,213,23,213};

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    filter(v);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}