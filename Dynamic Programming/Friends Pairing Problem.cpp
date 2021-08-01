int mod = pow(10, 9) + 7;
int dp[1000001];
int solve(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (long long int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] % mod + ((i - 1) % mod * dp[i - 2]) % mod) % mod;
    return dp[n];
}

int countFriendsPairings(int n)
{
    // code here
    memset(dp, -1, sizeof dp);
    return solve(n);
}