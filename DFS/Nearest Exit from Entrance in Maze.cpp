class Solution {
    int result;
    void solve(vector<vector<char>> &maze, vector<vector<bool>> vis, int m, int n, int i, int j, int d)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == true)
            return;
        if ((i == 0 && j >= 0 && j < n) || (j == 0 && i >= 0 && i < m) || (i == m - 1 && j >= 0 && j < n) || (j == n - 1 && i >= 0 && i < m))
        {
            result = min(d, result);
            return;
        }
        vis[i][j] = true;
        solve(maze, vis, m, n, i + 1, j, d + 1);
        solve(maze, vis, m, n, i, j - 1, d + 1);
        solve(maze, vis, m, n, i - 1, j, d + 1);
        solve(maze, vis, m, n, i, j + 1, d + 1);
        vis[i][j] = false;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        result = INT_MAX;
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maze[i][j] == '.')
                    vis[i][j] = true;
            }
        }
        solve(maze, vis, m, n, entrance[0] + 1, entrance[1], 1);
        solve(maze, vis, m, n, entrance[0], entrance[1] - 1, 1);
        solve(maze, vis, m, n, entrance[0] - 1, entrance[1], 1);
        solve(maze, vis, m, n, entrance[0], entrance[1] + 1, 1);
        return result == INT_MAX ? -1 : result;
    }
};