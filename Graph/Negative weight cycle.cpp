int isNegativeWeightCycle(int n, vector<vector<int>>edges)
{
	// Code here
	vector<int> dist(n, INT_MAX);
	dist[0] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (auto it : edges)
		{
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
				dist[v] = dist[u] + wt;
		}
	}

	for (auto it : edges)
	{
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
			return 1;
	}
	return 0;
}