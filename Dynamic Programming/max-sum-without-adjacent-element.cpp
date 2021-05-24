//DP CODE
int maxSum(vector<vector<int>> &A)
{
	int n = A[0].size();
	if (n == 0)
		return 0;
	if (n == 1)
		return max(A[0][0], A[1][0]);
	int dp[n];
	memset(dp, 0, sizeof dp);
	dp[0] = max(A[0][0], A[1][0]);
	for (int i = 1; i < n; i++)
	{
		if (i - 2 < 0)
			dp[i] = max(dp[i - 1], max(A[0][i], A[1][i]));
		else
			dp[i] = max(dp[i - 1], dp[i - 2] + max(A[0][i], A[1][i]));
	}
	return dp[n - 1];
}