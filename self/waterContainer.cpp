// https://leetcode.com/playground/B9HL7G2K
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int bucketSize = height.size() - 1;

        int leftIdx = 0;
        int rightIdx = bucketSize;
        int areaMax = INT_MIN;

        while (bucketSize != 0) {
            int temp;
            if (height[leftIdx] < height[rightIdx]) {
                temp = height[leftIdx] * bucketSize;
                leftIdx++;
            } else {
                temp = height[rightIdx] * bucketSize;
                rightIdx--;
            }
            if (temp > areaMax) {
                areaMax = temp;
            }
            bucketSize--;
        }
        return areaMax;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}