int dp[101][101][101];
int LCSof3Helper(string A, string B, string C, int n1, int n2, int n3)
{
    if (n1 == 0 || n2 == 0 || n3 == 0)
        return 0;

    if (dp[n1][n2][n3] != -1)
        return dp[n1][n2][n3];
    if (A[n1 - 1] == B[n2 - 1] && B[n2 - 1] == C[n3 - 1])
        dp[n1][n2][n3] = 1 + LCSof3Helper(A, B, C, n1 - 1, n2 - 1, n3 - 1);
    else
        dp[n1][n2][n3] = max(LCSof3Helper(A, B, C, n1 - 1, n2, n3), max(LCSof3Helper(A, B, C, n1, n2 - 1, n3), LCSof3Helper(A, B, C, n1, n2, n3 - 1)));
    return dp[n1][n2][n3];
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp, -1, sizeof dp);
    return LCSof3Helper(A, B, C, n1, n2, n3);
}

////////////////////////////////////////////////////////////////////////
//DP SOLUTION

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[n1 + 1][n2 + 1][n3 + 1];
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int k = 0; k <= n3; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }
    return dp[n1][n2][n3];
}