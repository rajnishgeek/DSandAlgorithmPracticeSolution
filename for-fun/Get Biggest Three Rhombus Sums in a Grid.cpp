//Amit's Approach
vector<int> getBiggestThree(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int i, j;
    vector<int>v;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            v.push_back(grid[i][j]);
            int k;
            for (k = 1;; k++)
            {
                if (j + k < m && j - k >= 0 && i + 2 * k < n)
                {
                    int x = 1, tmp = grid[i][j];
                    while (x <= k)
                    {
                        tmp += grid[i + x][j - x];
                        tmp += grid[i + x][j + x];
                        x++;
                    }
                    int u = k - 1;
                    while (x <= 2 * k)
                    {
                        tmp += grid[i + x][j - u];
                        tmp += grid[i + x][j + u];
                        x++;
                        u--;
                    }
                    tmp = tmp - grid[i + 2 * k][j];
                    v.push_back(tmp);
                    cout << tmp << " ";
                }
                else
                    break;
            }
        }
    }
    sort(v.begin(), v.end());
    vector<int>ans;
    for (i = v.size() - 1; i >= 0 && ans.size() < 3; i--)
    {
        if (ans.size() == 0)
            ans.push_back(v[i]);
        else
        {
            if (ans[ans.size() - 1] != v[i])
                ans.push_back(v[i]);
        }
    }
    return ans;
}
