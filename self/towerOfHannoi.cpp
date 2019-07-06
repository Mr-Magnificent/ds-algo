#include <iostream>
using namespace std;

void hanoi(int shells, int startTower, int destTower, int helpTower)
{
    // if (shells == 2)
    // {
    //     cout << "1 [ " << startTower << " --> " << helpTower << " ]" << endl;
    //     cout << "2 [ " << startTower << " --> " << destTower << " ]" << endl;
    //     cout << "1 [ " << helpTower  << " --> " << destTower << " ]" << endl;
    //     return;
    // }

    if(shells == 0) return;

    hanoi(shells - 1, startTower, helpTower, destTower);
    cout << shells << " [ " << startTower << " --> " << destTower << " ]" << endl;
    hanoi(shells - 1, helpTower, destTower, startTower);
}


int main(int argc, char **argv)
{
    int n;
    cout << "Enter the number of shells:\t";
    cin >> n;
    hanoi(n, 1, 2, 3);
}
