void DFS(vector<int> adj, vector<int> &visited, int node, int &vertices)
{
	visited[node] = true;
	vertices++;
	for (auto it : adj[node])
	{
		if (!visited[node])
		{
			DFS(adj, visited, it, vertices);
		}
	}
}

int journeyToMoon(int n, vector<vector<int>> astronaut)
{
	vector<int> adj[n];
	for (int i = 0; i < n; i++)
	{
		adj[astronaut[0]].push_back(astronaut[1]);
		ajd[astronaut[1]].push_back(astronaut[0]);
	}

	vector<bool> visited(n, false);
	vector<int> componenets;
	for (int i = 0; i < n; i++)
	{
		int vertices = 0;
		DFS(adj, visited, i, vertices);
		componenets.push_back(vertices);
	}

	int totalWay = n * (n - 1) / 2;
	for (int i = 0; i < componenets.size(); i++)
	{
		totalWay -= componenets[i] * (componenets[i] - 1) / 2;
	}
	return totalWay;
}