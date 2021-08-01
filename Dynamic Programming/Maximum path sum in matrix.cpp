{
    // code here
    if (N == 1)
        return Matrix[0][0];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j > 0 && j < N - 1)
                Matrix[i][j] += max(Matrix[i - 1][j], max(Matrix[i - 1][j - 1], Matrix[i - 1][j + 1]));
            else if (j == 0)
                Matrix[i][j] += max(Matrix[i - 1][j], Matrix[i - 1][j + 1]);
            else if (j == N - 1)
                Matrix[i][j] += max(Matrix[i - 1][j], Matrix[i - 1][j - 1]);
        }
    }
    int maxi = 0;
    for (int j = 0; j < N; j++)
        maxi = max(maxi, Matrix[N - 1][j]);
    return maxi;
}