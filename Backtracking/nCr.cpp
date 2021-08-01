int nCr(int n, int r) {
    // code he
    if (r > n)
        return 0;
    if (n == r || r == 0)
        return 1;
    int mod = pow(10, 9) + 7;
    int C[n + 1][r + 1];
    int i, j;

    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, r); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously
            // stored values
            else
                C[i][j] = (C[i - 1][j - 1] % mod + C[i - 1][j] % mod) % mod;
        }
    }

    return C[n][r] % mod;

}