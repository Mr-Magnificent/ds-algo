// find the numbers whose XOR, AND, OR is given
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int first = stoi(argv[1]);
    int second = stoi(argv[2]);

    int OR  = first | second;
    int AND = first & second;
    int XOR = first ^ second;

    int sum = AND + OR;

    bool found = false;
    for(int i = 0; i <= sum/2; i++) {
        int temp = sum - i;
        if ((temp ^ i) == XOR) {
            cout << "Elements are " << i << " " << temp << endl;
            found = true;
        }
    }

    if(!found) cout << "Elements not found" << endl;
}
