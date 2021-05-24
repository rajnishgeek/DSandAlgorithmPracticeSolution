long long dp[1001][1001];
long long knapsack(int w, const vector<int> &wt, const vector<int> &cost, int i) {

	if (w == 0) return 0;
	if (i >= wt.size()) return INT_MAX;
	if (dp[i][w] != -1) return dp[i][w];

	if (w - wt[i] >= 0)
		dp[i][w] = min(cost[i] + knapsack(w - wt[i], wt, cost, i), knapsack(w, wt, cost, i + 1));
	else
		dp[i][w] = knapsack(w, wt, cost, i + 1);

	return dp[i][w];
}


int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
	int n = A.size(), cost = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cost += (int)knapsack(A[i], B, C, 0);
	}
	return cost;

}
