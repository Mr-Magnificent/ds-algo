#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string n;
    cin >> n;
    int curBase, fuBase;
    string ans = "";
    cin >> curBase >> fuBase;
    int len = n.length();
    int* arr = new int[len];
    for(int i = 0; i < len; i++) {
        arr[i] = n[i] - '0';
    }
    int sum = 0;
    for(int i = len - 1; i >= 0; i--) {
        sum *= curBase;
        sum += arr[i];
        
    }
    if(sum) {
        ans += sum + '0';
    }
    cout << ans << endl;
    return 0;
}
