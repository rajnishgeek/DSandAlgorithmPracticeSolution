/*return true if any two value sum of array is equal to k else false
  time complexity is O(n)
  space complexity is O(1)
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool twosum(int, int, int);
int main()
{
	int a[] = { -5, -3, 5, 3, 7, 8};
	int n = sizeof(a) / sizeof(int);
	int k = 7;
	cout << twosum(a, n, k) << endl;
	return 0;
}

bool twosum(int a[], int n, int k)
{
	if (n == 0)
		return false;
	int i = 0, j = n - 1;
	while (i < j)
	{
		if ((a[i] + a[j]) < k)
			i--;

		else if ((a[i] + a[j]) > k)
			j--;

		else
			return true;
	}
	return false;
}