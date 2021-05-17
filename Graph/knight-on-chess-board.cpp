int knightOnChessBoard(int A, int B, int C, int D, int E, int F)
{
	if (C == E && D == F)
		return 0;

	vector<vector<bool>> visited(A, vector<bool> (B, false));
	vector<pair<int, int>> front = {{C, D}};
	pair<int, int> destination = {E, F};
	int level = 0;
	vector<int> dx = {1, 2, 2, 1, -2, -1, -2, -1};
	vector<int> dy = {2, 1, -1, -2, -1, -2, 1, 2};
	while (!front.empty())
	{
		vector<pair<int, int>> next;
		for (auto f : front)
		{
			if (visited[f.first - 1][f.second - 1])
				continue;
			visited[f.first - 1][f.second - 1] = true;
			if (f == destination)
				return level;
			for (int i = 0; i < 8; i++)
			{
				int x = f.first + dx[i];
				int y = f.second + dy[i];
				if (x < 1 || x > A || y < 1 || y > B)
					continue;
				if (!visited[x - 1][y - 1])
					next.push_back({x, y});
			}
		}
		front.next;
		level++;
	}
	return -1;
}