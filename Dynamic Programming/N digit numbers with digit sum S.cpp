//RECURSION APPROACH
unsigned long long int countRecursion(int n, int sum)
{
	if (n == 0)
		return sum == 0;
	if (sum == 1)
		return 1;
	unsigned long long  int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (sum - i >= 0)
			ans += countRecursion(n - 1, sum - i);
	}
	return ans;
}

unsigned long long int numberOfSum(int n, int sum)
{
	unsigned long long int ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (sum - i >= 0)
			ans += countRecursion(n - 1, sum - i);
	}
	return ans;
}

//******************************************************************************
//MEMOIZATION APPROACH
#define mod 1000000007
unsigned long long int dp[1001][1001];
unsigned long long int countRecursion(int n, int sum)
{
	if (n == 0)
		return sum == 0;
	if (dp[n][sum] != 0)
		return dp[n][sum];
	unsigned long long  int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (sum - i >= 0)
			ans = (ans % mod) + (countRecursion(n - 1, sum - i) % mod);
	}
	return dp[n][sum] = ans % mod;
}

unsigned long long int numberOfSum(int n, int sum)
{
	memset(dp, -1, sizeof dp);
	unsigned long long int ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (sum - i >= 0)
			ans = (ans % mod) + (countRecursion(n - 1, sum - i) % mod);
	}
	return ans % mod;
}