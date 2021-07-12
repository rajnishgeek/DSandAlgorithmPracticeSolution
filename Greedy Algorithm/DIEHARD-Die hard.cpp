#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int timeTaken(int h, int a, int curr)
{
	if (h <= 0 || a <= 0)
		return 0;
	if (dp[h][a] != -1)
		return dp[h][a];
	int x = 0, y = 0, z = 0;
	if (curr != 1)
		x = 1 + timeTaken(h + 3, a + 2, 1);
	if (curr != 2)
		y = 1 + timeTaken(h - 5, a - 10, 2);
	if (curr != 3)
		z = 1 + timeTaken(h - 20, a + 5, 3);
	return dp[h][a] = max(x, max(y, z));
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int h, a;
		cin >> h >> a;
		memset(dp, -1, sizeof dp);
		cout << max(timeTaken(h + 3, a + 2, 1), max(timeTaken(h - 5, a - 10, 2), timeTaken(h - 20, a + 5, 3))) << endl;
	}
	return 0;
}