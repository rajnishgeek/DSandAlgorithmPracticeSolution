vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
int DFS(vector<vector<int>> &max_from_here, vector<vector<int>> &matrix, int row, int col, int n, int m)
{
    if (max_from_here[row][col] != 0)
        return max_from_here[row][col];

    int maxi = 1;
    for (vector<int> d : dir)
    {
        int x = row + d[0];
        int y = col + d[1];
        if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] <= matrix[row][col])
            continue;
        int len = 1 + DFS(max_from_here, matrix, x, y, n, m);
        maxi = max(maxi, len);
    }
    max_from_here[row][col] = maxi;
    return maxi;
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    vector<vector<int>> max_from_here(matrix.size(), vector<int> (matrix[0].size(), 0));
    int maxPath = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            maxPath = max(maxPath, DFS(max_from_here, matrix, i, j, matrix.size(), matrix[i].size()));
        }
    }
    return maxPath;
}