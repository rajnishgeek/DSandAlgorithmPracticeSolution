bool isBipartiteHelper(vector<int> adj[], vector<int> &color, int source)
{
    queue<int> q;
    q.push(source);
    color[source] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}


bool isBipartite(int V, vector<int>adj[])
{
    // Code here
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (isBipartiteHelper(adj, color, i) == false)
                return false;
        }
    }

    return true;
}