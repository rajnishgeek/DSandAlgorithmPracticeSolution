int dp[10001][10001];
//e is egg,n is floor
int solve(int e, int n)
{
    if (dp[e][n] != -1)
        return dp[e][n];
    if (n == 0 || n == 1)
        return n;
    if (e == 1)
        return n;
    int minimum = INT_MAX, res;
    for (int k = 1; k <= n; k++)
    {
        res = max(solve(e - 1, n - 1), solve(e, n - k));
        if (res < minimum)
            minimum = res;

    }
    return dp[e][n] = (1 + minimum);
}

int superEggDrop(int k, int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(k, n);
}