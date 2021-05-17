void dfs(vector<int> &A, vector<int> adj, int node, vector<int> &visited, int count, int &path, int C)
{
	visited[node] = 1;
	if (A[node - 1] == 1)
		count++;
	if (adj[node].size() == 0)
	{
		if (count <= C)
			path++;
		return;
	}
	for (auto it : adj[node])
		if (visited[it] == 0)
			dfs(A, adj, it, visited, count, path, C);
}

int CountpathWithGoodNodes(vector<int> A, vector<vector<int>> &B, int C)
{
	if (A.size() == 0 || C == 0)
		return 0;
	vector<int> adj[A + 1];
	vector<int> visited[A + 1];
	for (int i = 0; i < B.size(); i++)
	{
		adj[B[i][0]].push_back(B[i][1]);
		adj[B[i][1]].push_back(B[i][0]);
	}

	int  count = A[0], path = A[0];
	for (auto it : adj[1])
		if (visited[it] == 0)
			dfs(A, adj, it, visited, count, path, C);
	return path;
}