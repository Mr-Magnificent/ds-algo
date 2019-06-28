#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int *arr;
    int size;
    bool isNegative = false;

    Array(int size)
    {
        this->arr = new int[size] {0};
        this->size = size;
    }

    Array(string s)
    {
        int i;
        if (s[0] == '-')
        {
            this->isNegative = true;
            this->size = s.length() - 1;
            i = 1;
        }
        else
        {
            this->isNegative = false;
            this->size = s.length();
            i = 0;
        }

        this->arr = new int[this->size]{0};

        for (int j = 0; j < size;j++, i++)
        {
            arr[j] = (s[i]) - '0';
        }
    }

    void display()
    {
        bool isNum = false;
        for (int i = 0; i < this->size; i++)
        {
            if (arr[i] != 0) isNum = true;
            if(isNum) cout << arr[i] << " ";
        }
        if(!isNum) cout << 0;
        cout << endl;
    }
};

Array *scalarMul(const Array *n1, const int &n2, const int &resSize, const int &padding)
{
    Array *result = new Array(resSize);
    int resInd = resSize - 1;
    int ind = n1->size - 1;
    int carry = 0;
    while (ind >= 0)
    {
        int temp = carry;
        temp += n1->arr[ind] * n2;

        carry = temp / 10;
        result->arr[resInd - padding] = temp % 10;
        resInd--;
        ind--;
    }
    if (carry)
    {
        result[0] = carry;
    }
    return result;
}

Array *partialSum(const Array *partVal, const Array *partMul)
{
    Array *temp = new Array(partVal->size);
    bool carry = 0;

    int ind = temp->size - 1;
    int partMulInd = partMul->size - 1;
    int partValInd = partVal->size - 1;
    while (ind)
    {
        int val = carry;

        if (partMulInd >= 0)
        {
            val += partMul->arr[partMulInd];
            partMulInd--;
        }

        if (partValInd >= 0)
        {
            val += partVal->arr[partValInd];
            partValInd--;
        }

        temp->arr[ind] = val % 10;
        carry = val / 10;
        ind--;
    }
    if (carry) {
        temp->arr[partValInd] = carry;
    }
   

    delete partVal;
    delete partMul;
    return temp;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string n1str;
    string n2str;
    cin >> n1str >> n2str;

    Array *n1 = new Array(n1str);
    Array *n2 = new Array(n2str);
    Array *partSum = new Array(n1->size + n2->size);

    int resSize = partSum->size;

    int n2ind = n2->size - 1;
    while (n2ind >= 0)
    {
        Array *partialMul = scalarMul(n1, n2->arr[n2ind], resSize, (resSize - n2ind - n1->size - 1));
        partialMul->display();
        partSum = partialSum(partSum, partialMul);
        n2ind--;
    }
    if(n1->isNegative && !n2->isNegative || !n1->isNegative && n2->isNegative) cout << "- ";
    partSum->display();
}
