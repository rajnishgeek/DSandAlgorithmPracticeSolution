//RECURSION SOLUTION - time O(N sqrt(N))
int minSquare(int n)
{
	if (n <= 3)
		return 3;
	int ans = n;
	for (int i = 1; i * i <= N; i++)
		ans = (ans, 1 + minSquare(n - i * i));
	return ans;
}

//************************************************
//MEMOIZATION
vector<int> dp;

int minSquareHelper(int n)
{
	if (n <= 3)
		return 3;
	if (dp[n] != -1)
		return dp[n];
	int ans = n;
	for (int i = 1; i * i <= n; i++)
		ans = min(ans, 1 + minSquareHelper(n - i * i));
	return dp[n] = ans;
}

int minSquare(int n)
{
	dp.resize(n + 1, -1);
	return minSquareHelper(n);
}

//*********************************************************
//DP CODE
int minSquare(int n)
{
	int dp[n + 1];
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			int sq = j * j;
			dp[i] = min(dp[i], 1 + dp[i - sq]);
		}
	}
	return dp[n];
}