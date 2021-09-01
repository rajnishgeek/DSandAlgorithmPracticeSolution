int livingLifes(vector<vector<int>> &borad, int m, int n, int row, int col)
{
	int live = 0;
	for (int i = max(row - 1, 0); i <= min(m - 1, row + 1); i++)
	{
		for (int j = max(col - 1, 0); j <= min(col + 1, n - 1); j++)
		{
			live += borad[i][j] & 1;
		}
	}
	live -= borad[row][col] & 1;
	return live;
}

void gameOfLife(vector<vector<int>>& board)
{
	int m = board.size(), n = board[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int lives = livingLifes(board, m, n, i, j);
			if (board[i][j] == 1 && lives >= 2 && lives <= 3)
				board[i][j] = 3;
			else if (board[i][j] == 0 && lives == 3)
				board[i][j] = 2;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			board[i][j] >>= 1;
	}
}