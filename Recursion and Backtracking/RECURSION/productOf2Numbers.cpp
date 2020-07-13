#include<bits/stdc++.h>
using namespace std;

int productOfTwoNumbers(int x, int y, int times = 0, int sum = 0)
{
	if (times == y)
		return sum;
	sum += x;
	return productOfTwoNumbers(x, y, times + 1, sum);
}
int main()
{
	int x = 5, y = 2;
	cout << productOfTwoNumbers(x, y) << endl;
	return 0;
}