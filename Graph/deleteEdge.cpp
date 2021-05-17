#define M 1000000007
void dfs(vector<int> adj[], int u, int parent, long &ans, long sum, vector<int> &A) {
	int x = A[u - 1];

	for (auto& ch : adj[u]) {
		if (ch != parent) {
			dfs(adj, ch, u, ans, sum, A);
			x += A[ch - 1];
		}
	}
	A[u - 1] = x;

	if (u == 1)
		return;

	ans = max(ans, (x * (sum - x)) % M) % M;
}
int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
	int n = A.size();
	vector<int> adj[n + 1];
	for (auto& x : B) {
		adj[x[0]].push_back(x[1]);
		adj[x[1]].push_back(x[0]);
	}
	long sum = 0;
	for (auto& x : A) sum += x;
	long ans = 0;
	dfs(adj, 1, 0, ans, sum, A);
	return ans;
}

