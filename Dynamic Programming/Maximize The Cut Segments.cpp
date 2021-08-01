int dp[10001];
int solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
    if (x <= n)
        op1 = solve(n - x, x, y, z);
    if (y <= n)
        op2 = solve(n - y, x, y, z);
    if (z <= n)
        op3 = solve(n - z, x, y, z);
    return dp[n] = 1 + max(op1, max(op2, op3));
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    //vector<int> dp(10001, -1);
    memset(dp, -1, sizeof (dp));
    int result = solve(n, x, y, z);
    if (result < 0)
        return 0;
    return result;
}