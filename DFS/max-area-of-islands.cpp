int DFS(vector<vector<int>> &grid, int m, int n, int row, int col)
    {
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0)
            return 0;
        grid[row][col]=0;
        return 1+DFS(grid, m, n, row+1, col)+DFS(grid, m, n, row, col+1)+DFS(grid, m, n, row-1, col)+DFS(grid, m, n, row, col-1);
    }
    

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int maxArea=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int value=DFS(grid, m, n, i, j);
                    if(maxArea<value)
                     maxArea=value;
                }
            }
        }
        return maxArea;
    }