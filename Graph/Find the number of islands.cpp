void solve(vector<vector<char>> &grid, int m,  int n, int row, int col)
{
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '#' || grid[row][col] == '0')
        return;
    grid[row][col] = '#';
    solve(grid, m, n, row, col - 1);
    solve(grid, m, n, row - 1, col - 1);
    solve(grid, m, n, row - 1, col);
    solve(grid, m, n, row - 1, col + 1);
    solve(grid, m, n, row, col + 1);
    solve(grid, m, n, row + 1, col + 1);
    solve(grid, m, n, row + 1, col);
    solve(grid, m, n, row + 1, col - 1);
}

//Function to find the number of islands.
int numIslands(vector<vector<char>>& grid)
{
    // Code here
    int m = grid.size();;
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                solve(grid, m, n, i, j);
            }
        }
    }
    return count;
}