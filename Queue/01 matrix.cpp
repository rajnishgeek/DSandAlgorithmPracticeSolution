vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    int m = mat.size();
    int n = mat[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
                q.push({i, j});
            else
                mat[i][j] = INT_MAX;
        }
    }

    vector<vector<int>> dir({{ -1, 0}, {1, 0}, {0, -1}, {0, 1}});
    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();
        for (vector<int> d : dir)
        {
            int row = cell.first + d[0];
            int col = cell.second + d[1];
            if (row < 0 || row >= m || col < 0 || col >= n || mat[row][col] <= mat[cell.first][cell.second] + 1)
                continue;
            q.push({row, col});
            mat[row][col] = mat[cell.first][cell.second] + 1;
        }
    }
    return mat;
}