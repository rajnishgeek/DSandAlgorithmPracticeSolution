//RECURSION CODE
int longestChainSubsequence(vector<vector<int>> &A, int n, int lastElement)
{
	if (n == 0)
		return 0;

	if (A[n - 1][1] < lastElement)
		return = max(1 + longestChainSubsequence(A, n - 1, A[n - 1][0]), longestChainSubsequence(A, n - 1, lastElement));
	return = longestChainSubsequence(A, n - 1, lastElement);
}

int solve(vector<vector<int>> &A)
{
	return longestChainSubsequence(A, A.size(), INT_MAX);
}



//***************************************************************************************************************
//MEMOIZATION CODE
int dp[10002][10002];
int longestChainSubsequence(vector<vector<int>> &A, int n, int lastElement)
{
	if (n == 0)
		return 0;
	if (dp[n][lastElement] != -1)
		return dp[n][lastElement];
	if (A[n - 1][1] < lastElement)
		dp[n] = max(1 + longestChainSubsequence(A, n - 1, A[n - 1][0]), longestChainSubsequence(A, n - 1, lastElement));
	else
		dp[n] = longestChainSubsequence(A, n - 1, lastElement);
	return dp[n];
}

int solve(vector<vector<int>> &A)
{
	memset(dp, -1, sizeof dp);
	return longestChainSubsequence(A, A.size(), 10001);
}


//****************************************************************************************************************
//DP SOLUTION
int longestChainSubsequence(vector<vector<int>> &A)
{
	vector<int> dp(A.size(), 1);
	for (int i = 1; i < A.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j][1] < A[i][0] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	return *max_element(dp.begin(), dp.end());
}