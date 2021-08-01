class Solution
{
	class Cell {
	public:
		int x, y;
		int dist;
		Cell() {}
		Cell(int i, int j, int d)
		{
			x = i;
			y = j;
			dist = d;
		}
	};

	bool inside(int x, int y, int n)
	{
		return (x >= 1 && x <= n && y >= 1 && y <= n);
	}

public:
	//Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
	{
		// Code here
		int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2};
		int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1};

		queue<Cell> q;
		q.push(Cell(KnightPos[0], KnightPos[1], 0));
		Cell temp;
		int x, y;
		bool visited[N + 1][N + 1];

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				visited[i][j] = false;
		}

		visited[KnightPos[0]][KnightPos[1]] = true;

		while (!q.empty())
		{
			temp = q.front();
			q.pop();

			if (temp.x == TargetPos[0] && temp.y == TargetPos[1])
				return temp.dist;
			for (int i = 0; i < 8; i++)
			{
				int row = temp.x + dx[i];
				int col = temp.y + dy[i];

				if (inside(row, col, N) && visited[row][col] == false)
				{
					visited[row][col] = true;
					q.push(Cell(row, col, temp.dist + 1));
				}
			}
		}
		return 0;
	}
};