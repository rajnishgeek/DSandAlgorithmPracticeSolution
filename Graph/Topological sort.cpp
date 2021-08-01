vector<int> topoSort(int V, vector<int> adj[])
{
	// code here
	queue<int> q;
	vector<int> topo_sort;
	vector<int> inDegree(V, 0);

	//insert all node in degree
	for (int i = 0; i < V; i++)
	{
		for (auto it : adj[i])
			inDegree[it]++;
	}

	//push all vertex which has indegree 0
	for (int i = 0; i < V; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		topo_sort.push_back(node);
		for (auto it : adj[node])
		{
			inDegree[it]--;
			if (inDegree[it] == 0)
				q.push(it);
		}
	}
	return topo_sort;
}