#include<bits/stdc++.h>
using namespace std;
int minTime(int a[], int n, int p)
{
	int start_time = 0, end_time = 10e8, ans = 0;
	while (start_time <= end_time)
	{
		int mid = start_time + (end_time - start_time) / 2;
		int time = 0, parathas = 0;
		for (int i = 0; i < n; i++)
		{
			time = a[i];
			int j = 2;
			while (time <= mid)
			{
				parathas++;
				time += a[i] * j++;
			}
		}
		if (parathas >= p)
		{
			ans = mid;
			end_time = mid - 1;
		}
		else
			start_time = mid + 1;
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int p, l;
		cin >> p >> l;
		int a[l];
		for (int i = 0; i < l; i++)
			cin >> a[i];
		cout << minTime(a, l, p) << endl;
	}
	return 0;
}