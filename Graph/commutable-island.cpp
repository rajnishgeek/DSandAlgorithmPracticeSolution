bool comp(const vector<int> &a, const vector<int> &b)
{
	return a[2] < b[2];
}

int findParent(int u, vector<int> &parent)
{
	if (u == parent[u])
		return u;
	return findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &size)
{
	u = findParent(u, parent);
	v = findParent(v, parent);
	if (size[u] < size[v])
	{
		parent[u] = v;
		size[v] += size[u];
	}
	else
	{
		parent[v] = u;
		size[u] += size[v];
	}
}

int minCost(int A, vector<vector<int>> B)
{
	sort(B.begin(), B.end(), comp);
	vector<int> parent(A);
	for (int i = 0; i < A; i++)
		parent[i] = i;

	vector<int> rank(A, 0);
	int cost = 0;
	vector<pair<int, int>> mst;
	for (int i = 0; i < B.size(); i++)
	{
		int u = B[i][0];
		int v = B[i][1];
		int wt = B[i][2];
		if (findParent(v, parent) != findParent(u, parent))
		{
			cost += wt;
			mst.push_back({u, v});
			unionn(u, v, parent, rank);
		}
	}
	return cost;
}