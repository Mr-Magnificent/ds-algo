#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr1 {1,1,1,3,4,5,5,5,7,7,8,8};
    vector<int> arr2 {1,1,3,4,5,5,7,7,8,8};

    int ind1 = 0;
    int ind2 = 0;
    while(ind1 < arr1.size() && ind2 < arr2.size()) {
        if(arr1[ind1] == arr2[ind2]) {
            cout << arr1[ind1];
            ind1++;
            ind2++;
        } else if(arr1[ind1] > arr2[ind2]) {
            ind2++;
        } else {
            ind1++;
        }
    }
    cout << endl;
    return 0;
}
