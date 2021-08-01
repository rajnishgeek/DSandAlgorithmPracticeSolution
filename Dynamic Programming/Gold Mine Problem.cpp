int maxGold(int n, int m, vector<vector<int>> M)
{
    int goldTable[n][m];
    memset(goldTable, 0, sizeof(goldTable));

    for (int col = m - 1; col >= 0; col--)
    {
        for (int row = 0; row < n; row++)
        {
            // Gold collected on going to the cell on the right(->)
            int right = (col == m - 1) ? 0 : goldTable[row][col + 1];

            // Gold collected on going to the cell to right up (/)
            int right_up = (row == 0 || col == m - 1) ? 0 :
                           goldTable[row - 1][col + 1];

            // Gold collected on going to the cell to right down (\)
            int right_down = (row == n - 1 || col == m - 1) ? 0 :
                             goldTable[row + 1][col + 1];

            // Max gold collected from taking either of the
            // above 3 paths
            goldTable[row][col] = M[row][col] +
                                  max(right, max(right_up, right_down));

        }
    }

    // The max amount of gold collected will be the max
    // value in first column of all rows
    int res = goldTable[0][0];
    for (int i = 1; i < n; i++)
        res = max(res, goldTable[i][0]);
    return res;

}