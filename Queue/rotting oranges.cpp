class Solution {

    int R, C;
    struct element {
        int x, y;
    };

    bool isValid(int i, int j)
    {
        return (i >= 0 && j >= 0 && i < R && j < C);
    }

    bool isDelimeter(element temp)
    {
        return (temp.x == -1 && temp.y == -1);
    }

    bool isFreshOrange(vector<vector<int>>& arr)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (arr[i][j] == 1)
                    return true;
            }
        }
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        R = grid.size();
        C = grid[0].size();
        queue<element> pq;
        element temp;
        int ans = 0;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (grid[i][j] == 2)
                {
                    temp.x = i;
                    temp.y = j;
                    pq.push(temp);
                }
            }
        }

        temp.x = -1;
        temp.y = -1;
        pq.push(temp);


        while (!pq.empty())
        {
            bool isIncrement = false;
            while (!isDelimeter(pq.front()))
            {
                temp = pq.front();
                //bottom adjacent
                if (isValid(temp.x + 1, temp.y) && grid[temp.x + 1][temp.y] == 1)
                {
                    if (!isIncrement)
                    {
                        ans++;
                        isIncrement = true;
                    }
                    grid[temp.x + 1][temp.y] = 2;
                    temp.x++;
                    pq.push(temp);
                    temp.x--;
                }

                //up adjacent
                if (isValid(temp.x - 1, temp.y) && grid[temp.x - 1][temp.y] == 1)
                {
                    if (!isIncrement)
                    {
                        ans++;
                        isIncrement = true;
                    }
                    grid[temp.x - 1][temp.y] = 2;
                    temp.x--;
                    pq.push(temp);
                    temp.x++;
                }

                //left adjacent
                if (isValid(temp.x, temp.y - 1) && grid[temp.x ][temp.y - 1] == 1)
                {
                    if (!isIncrement)
                    {
                        ans++;
                        isIncrement = true;
                    }
                    grid[temp.x][temp.y - 1] = 2;
                    temp.y--;
                    pq.push(temp);
                    temp.y++;
                }

                //right adjacent
                if (isValid(temp.x, temp.y + 1) && grid[temp.x][temp.y + 1] == 1)
                {
                    if (!isIncrement)
                    {
                        ans++;
                        isIncrement = true;
                    }
                    grid[temp.x][temp.y + 1] = 2;
                    temp.y++;
                    pq.push(temp);
                    temp.y--;
                }

                pq.pop();
            }

            pq.pop();
            if (!pq.empty())
            {
                temp.x = -1;
                temp.y = -1;
                pq.push(temp);
            }
        }
        return isFreshOrange(grid) ? -1 : ans;
    }
};