void shortest_distance(vector<vector<int>>&matrix)
{
	// Code here
	int V = matrix.size();
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (matrix[i][j] == -1)
				matrix[i][j] = INT_MAX;
		}
	}

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
					continue;
				else if (matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			if (matrix[i][j] == INT_MAX)
				matrix[i][j] = -1;
	}
}