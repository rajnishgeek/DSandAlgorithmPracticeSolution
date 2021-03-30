#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];

void totalPaths(int m, int n, int i, int j, int &count)
{
	if (i >= m || j >= n)
		return;
	if (i == m - 1 && j == n - 1)
	{
		count++;
		return;
	}
	if (a[i][j] == '#')
		return;

	totalPaths(m, n, i, j + 1, count);
	totalPaths(m, n, i + 1, j, count);
	return;
}
int main()
{
	int m, n, i, j, count = 0;
	cin >> m >> n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	}
	totalPaths(m, n, 0, 0, count);
	cout << count << endl;
	return 0;
}
