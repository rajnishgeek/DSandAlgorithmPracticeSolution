//recursion solution
int solve(int a[], int n, int lastElement)
{
	if (n == 0)
		return 0;
	if (lastElement > a[n - 1])
	{
		return max(a[n - 1] + solve(a, n - 1, a[n - 1]), solve(a, n - 1, lastElement));
	}
	else
		return solve(a, n - 1, lastElement);
}

int maxSumIS(int arr[], int n)
{
	// Your code goes here
	return solve(arr, n, INT_MAX);


/////////////////////////////////////////////////////////////////////////////////////
//Dp solution

	int maxSumIS(int arr[], int n)
	{
		// Your code goes here
		int dp[n];
		for (int i = 0; i < n; i++)
			dp[i] = arr[i];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[j] < arr[i] && dp[i] < arr[i] + dp[j])
					dp[i] = arr[i] + dp[j];
			}
		}
		int maxSum = 0;
		for (int i = 0; i < n; i++)
			maxSum = max(maxSum, dp[i]);
		return maxSum;
	}