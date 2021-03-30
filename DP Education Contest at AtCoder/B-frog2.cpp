#include<bits/stdc++.h>
using namespace std;

int minCostHealper(int a[], int n, int k, int i)
{
	if (i < 0)
		return INT_MAX;
	if (i == 0 )
		return 0;
	int temp = INT_MAX;
	for (int j = 1; j <= k; j++)
	{
		int step = 0;
		if (i - j >= 0)
		{
			step = abs(a[i] - a[i - j]);
		}
		step += minCostHealper(a, n, k - 1, i - j);
		temp = min(temp, step);
	}
	return temp;
}

int minCost(int a[], int n, int k)
{
	if (k <= 0 || n <= 0)
		return 0;
	if (k > n)
		return minCostHealper(a, n, n, n - 1);
	else
		return minCostHealper(a, n, k, n - 1);
}
int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << minCost(a, n, k) << endl;
	return 0;
}
