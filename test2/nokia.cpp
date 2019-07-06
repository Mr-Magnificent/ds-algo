#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> codes = {".", "abc", "def", "gh", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

int keyPad(string str, string ans, int ind)
{
    //write your code here
    int count = 0;
    if(ind == str.length()) {
        cout << ans << endl;
        return 1;
    }
    for(char ele: codes[(str[ind] - '0')]) {
        string temp(1, ele);
        count += keyPad(str, ans + ele, ind + 1);
    }
    return count;
}

//Driver program
int main(int argc, char **argv)
{
    string s;
    cin >> s;

    int ans = keyPad(s, "", 0);
    cout << ans << endl;
}
