#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unsigned long long divisors(int x)
{
	unsigned long long count = 0;
	long i;
	for (i = 1; i * i < x; i++)
	{
		if (x % i == 0)
		{
			count += i;
			count += (x / i);
		}
	}
	if (i * i == x)
	{
		count += i;
	}
	return count;
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	unsigned long l1, r1;
	cin >> l1 >> r1;
	unsigned long l2, r2;
	cin >> l2 >> r2;

	if ((r1 - l1 + 1) > (r2 - l2 + 1) && r1 > r2)
	{
		cout << "A\n";
	}
	else if ((r1 - l1 + 1) < (r2 - l2 + 1) && r1 < r2)
	{
		cout << "B\n";
	}
	else if ((r1 - l1 + 1) < (r2 - l2 + 1) && r1 > r2) {
		long sum1 = 0;
		long sum2 = 0;
		for (int i = l1; i <=r1; i++) {
			sum1 += i;
		}
		for (int i = l2; i <= r2; i++)
		{
			sum2 += i;
		}
		if (sum1 > sum2)
		{
			cout << "A\n";
		}
		else if (sum1 == sum2)
		{
			cout << "Draw\n";
		}
		else
		{
			cout << "B\n";
		}
	}
	else if ((r1 - l1 + 1) > (r2 - l2 + 1) && r1 < r2)
	{
		long sum1 = 0;
		long sum2 = 0;
		for (int i = l1; i <= r1; i++)
		{
			sum1 += i;
		}
		for (int i = l2; i <= r2; i++)
		{
			sum2 += i;
		}
		if (sum1 > sum2)
		{
			cout << "A\n";
		}
		else if (sum1 == sum2)
		{
			cout << "Draw\n";
		}
		else
		{
			cout << "B\n";
		}
	}
	// cout << divisors(10) << endl;
	return 0;
}
