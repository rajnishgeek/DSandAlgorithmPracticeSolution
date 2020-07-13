#include<bits/stdc++.h>
using namespace std;

int countWaysHealper(int x, int n, int digit)
{
	int value = x - pow(digit, n);
	if (value == 0)
		return 1;
	if (value < 0)
		return 0;
	return (countWaysHealper(value, n, digit + 1) + countWaysHealper(x, n, digit + 1));
}
int countWays(int x, int n)
{
	return countWaysHealper(x, n, 1);
}
int main()
{
	int x = 100, n = 2;
	cout << countWays(x, n);
	return 0;
}
