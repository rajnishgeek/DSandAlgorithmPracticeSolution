#include<bits/stdc++.h>
using namespace std;

int maxPoints(int a[][4], int n, int day, int task)
{
	if (day == n)
		return 0;
	int maxi = 0;
	if (task == 0)
	{
		maxi = max(maxi, a[day][1] + maxPoints(a, n, day + 1, 1));
		maxi = max(maxi, a[day][2] + maxPoints(a, n, day + 1, 2));
		maxi = max(maxi, a[day][3] + maxPoints(a, n, day + 1, 3));
	}
	else if (task == 1)
	{
		maxi = max(maxi, a[day][2] + maxPoints(a, n, day + 1, 2));
		maxi = max(maxi, a[day][3] + maxPoints(a, n, day + 1, 3));
	}
	else if (task == 2)
	{
		maxi = max(maxi, a[day][1] + maxPoints(a, n, day + 1, 1));
		maxi = max(maxi, a[day][3] + maxPoints(a, n, day + 1, 3));
	}
	else if (task == 3)
	{
		maxi = max(maxi, a[day][1] + maxPoints(a, n, day + 1, 1));
		maxi = max(maxi, a[day][2] + maxPoints(a, n, day + 1, 2));
	}
	return maxi;
}

int main()
{
	int n;
	cin >> n;
	int a[n][4];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	cout << maxPoints(a, n, 0, 0) << endl;
	return 0;
}
