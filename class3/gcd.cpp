#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int fir, sec;
    cout << "Enter the elements: ";
    cin >> fir >> sec;

    int rem = sec % fir;

    while (rem != 0) {
        sec = fir;
        fir = rem;
        rem = sec % fir;
    }
    cout << fir << endl;
}