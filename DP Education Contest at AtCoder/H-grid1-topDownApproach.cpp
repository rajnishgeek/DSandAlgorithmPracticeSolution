#include<bits/stdc++.h>
using namespace std;
#define d (10^9)+7
char a[1000][1000];
int dp[1000][1000];

int totalPaths(int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			dp[i][j] = 0;

	for (i = 0; i < m; i++)
	{
		if (a[i][0] == '#')
			dp[i][0] = 0;
		else
			dp[i][0] = 1;
	}

	for (j = 0; j < n; j++)
	{
		if (a[0][j] == '#')
			dp[0][j] = 0;
		else
			dp[0][j] = 1;
	}

	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (a[i][j] == '#')
				continue;
			else
				dp[i][j] = (dp[i - 1][j]% d + dp[i][j - 1]% d) ;
		}
	}
	return (dp[m - 1][n - 1]) % d;
}

int main()
{
	int m, n, i, j;
	cin >> m >> n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	}

	cout << totalPaths(m, n) << endl;
	return 0;
}
