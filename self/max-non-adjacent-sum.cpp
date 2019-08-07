#include <iostream>
#include <vector>
using namespace std;

int FindMaxSumNonAdjacent(vector<int> &elements)
{
    vector<int> solution(elements.size(), 0);
    for (int i = 0; i < solution.size(); i++)
    {
        if (i == 0)
        {
            solution[i] = (elements[i] >= 0) ? elements[i] : 0;
        }
        else if (i == 1)
        {
            solution[i] = (elements[i] >= 0) ? elements[i] : 0;
        }
        else if (i == 2)
        {
            int sum = 0;
            sum += (elements[0] >= 0) ? elements[0] : 0;
            sum += (elements[i] >= 0) ? elements[i] : 0;
            solution[i] = sum;
        }
        else
        {
            int sum = 0;
            int temp = max(solution[i - 2], solution[i - 3]);
            sum += (temp >= 0) ? temp : 0;
            solution[i] = max(sum, sum + elements[i]);
        }
    }

    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << " ";
    }
    cout << endl;
    
    return max(solution[solution.size() - 1], solution[solution.size() - 2]);
}

int main(int argc, char **argv)
{
    vector<int> elements({1, 0, 3, 9, 2, -1, -3, 0, -2});
    cout << FindMaxSumNonAdjacent(elements) << endl;
}