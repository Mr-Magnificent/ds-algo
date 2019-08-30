#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int rc = 2 * n - 1;

    int mid = rc >> 1;

    int stars = 1;
    int incr = true;

    for (int i = 0; i < rc; i++)
    {
        int tempstars = stars;
        for (int j = 0; j < rc; j++)
        {
            if (j >= mid && tempstars > 0)
            {
                cout << "* ";
                tempstars--;
            }
            else
            {
                cout << " ";
            }
        }
        if (i == n - 1)
        {
            incr = false;
        }

        if (incr)
        {
            stars++;
            mid--;
        }
        else
        {
            stars--;
            mid++;
        }
        cout << endl;
    }
}