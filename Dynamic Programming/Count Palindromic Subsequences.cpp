long long int dp[1001][1001];
long long int  countPSHelper(string s, int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return dp[i][j] = 1;
    if (s[i] == s[j])
        return dp[i][j] = 1 + countPSHelper(s, i + 1, j) + countPSHelper(s, i, j - 1);
    else if (s[i] != s[j])
        return dp[i][j] = countPSHelper(s, i + 1, j) + countPSHelper(s, i, j - 1) + countPSHelper(s, i + 1, j - 1);
}

long long int  countPS(string str)
{
    memset(dp, -1, sizeof(dp));
    return countPSHelper(str, 0, str.size() - 1);
}