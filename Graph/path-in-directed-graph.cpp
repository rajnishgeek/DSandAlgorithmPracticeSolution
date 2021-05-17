bool dfs(vector<int> adj[], int node, vector<int> &visited, int lastNode)
{
    if (node == lastNode)
        return true;
    visited[node] = 1;
    bool res = false;
    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            res = dfs(adj, it, visited, lastNode);
            if (res)
                return true;
        }
    }
    return res;
}

int Solution::solve(int A, vector<vector<int> > &B)
{
    if (A <= 1)
        return 0;
    vector<int> visited(A + 1, 0);
    vector<int> adj[A + 1];

    for (int i = 0; i < B.size(); i++)
        adj[B[i][0]].push_back(B[i][1]);

    bool res = false;
    visited[1] = 1;
    for (auto it : adj[1])
    {
        if (visited[it] == 0)
        {
            res = dfs(adj, it, visited, A);
            if (res)
                return 1;
        }
    }
    return 0;
}
