class QItem {
public:
    int row, col, dist;
    QItem(int x, int y, int w)
    {
        row = x;
        col = y;
        dist = w;
    }
}:

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    QItem source(0, 0, 0);
    int m = grid.size();
    int n = grid[0].size();
    bool visited[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                visited[i][j] = true;
            else
                visited[i][j] = false;
        }
    }
    source.row = 0;
    source.col = 0;

    queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty())
    {
        QItem p = q.front();
        q.pop();

        if (p.row == m - 1 && p.col == n - 1)
            return p.dist;

        //up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false)
        {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }

        //down
        if (p.row + 1 < m && visited[p.row + 1][p.col] == false)
        {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }

        //left
        if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false)
        {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }

        //right
        if (p.col + 1 < n && visited[p.row][p.col + 1] == false)
        {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }

        //top left
        if (p.row - 1 >= 0 && p.col - 1 >= 0 visited[p.row - 1][p.col - 1] == false)
        {
            q.push(QItem(p.row - 1, p.col - 1, p.dist + 1));
            visited[p.row - 1][p.col - 1] = true;
        }

        //top right
        if (p.row - 1 >= 0 && p.col + 1 < n visited[p.row - 1][p.col + 1] == false)
        {
            q.push(QItem(p.row - 1, p.col + 1, p.dist + 1));
            visited[p.row - 1][p.col + 1] = true;
        }

        //bottom right
        if (p.row + 1 < m && p.col + 1 < n visited[p.row + 1][p.col + 1] == false)
        {
            q.push(QItem(p.row + 1, p.col + 1, p.dist + 1));
            visited[p.row + 1][p.col + 1] = true;
        }

        //bottom left
        if (p.row + 1 < m && p.col - 1 >= 0 visited[p.row + 1][p.col - 1] == false)
        {
            q.push(QItem(p.row + 1, p.col - 1, p.dist + 1));
            visited[p.row + 1][p.col - 1] = true;
        }
    }
    return -1;
}