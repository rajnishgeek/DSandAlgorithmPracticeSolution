void solve(vector<pair<int, int>> adj, vector<bool> &visited, int src, int dst, int k, int totolCost, int &fare)
{
    if (k < -1)
        return;
    if (src == dst)
    {
        fare = min(fare, totolCost);
        return;
    }

    visited[src] = true;
    for (auto it : adj[src])
    {
        if (visited[it.first] == false && (totolCost + it.second <= fare))
            solve(adj, visited, it.first, dst, k - 1, totolCost + it.second, fare);
    }
    visited[src] = false;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    // pair first if node, second is weight
    for (int i = 0; i < n; i++)
    {
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    vector<bool> visited(n, false);
    int fare = INT_MAX;
    solve(adj, visited, src, dst, k, 0, fare);
    return fare == INT_MAX ? -1 : fare;
}