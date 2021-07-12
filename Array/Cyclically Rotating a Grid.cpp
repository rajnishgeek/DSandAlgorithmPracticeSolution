vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    int till = min(m, n) / 2;

    for (int l = 0; l < till; l++)
    {
        vector<int> v;

        //top row
        for (int col = l; col < n - l - 1; col++)
            v.push_back(grid[l][col]);

        //right
        for (int row = l; row < m - 1 - l; row++)
            v.push_back(grid[row][n - 1 - l]);

        //bottom row
        for (int col = n - 1 - l; col > l; col--)
            v.push_back(grid[m - 1 - l][col]);

        //left
        for (int row = m - 1 - l; row > l; row--)
            v.push_back(grid[row][l]);

        //assign it back to the grid form the stored array at position start
        int start = k % v.size();

        //top row
        for (int col = l; col < n - l - 1; col++)
            grid[l][col] = v[start++ % v.size()];

        //right
        for (int row = l; row < m - 1 - l; row++)
            grid[row][n - 1 - l] = v[start++ % v.size()];;

        //bottom row
        for (int col = n - 1 - l; col > l; col--)
            grid[m - 1 - l][col] = v[start++ % v.size()];;

        //left
        for (int row = m - 1 - l; row > l; row--)
            grid[row][l] = v[start++ % v.size()];;
    }
    return grid;
}