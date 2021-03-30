#include<bits/stdc++.h>
using namespace std;
int maxPathSum(int a[], int b[], int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	int i = 0, sum1 = 0;
	int j = 0, sum2 = 0;
	int res = 0;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
			sum1 += a[i++];
		else if (a[i] > b[j])
			sum2 += b[j++];
		else
		{
			res += max(sum1, sum2) + a[i];
			sum1 = sum2 = 0;
			i++;
			j++;
		}
	}

	while (i < m)
		sum1 += a[i++];
	while (j < n)
		sum2 += b[j++];
	res += max(sum1, sum2);
	return res;
}

int main()
{
	while (true)
	{
		int m;
		cin >> m;
		if (m == 0)
			break;
		else
		{
			int a[m];
			int	n, i;
			for (i = 0; i < m; i++)
				cin >> a[i];
			cin >> n;
			int b[n];
			for (i = 0; i < n; i++)
				cin >> b[i];
			cout << maxPathSum(a, b, m, n) << endl;
		}
	}
	return 0;
}