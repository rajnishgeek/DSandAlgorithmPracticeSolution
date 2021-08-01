void dfs(vector<int> adj[], vector<int> &visited, stack<int> &st, int node)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
            dfs(adj, visited, st, it);
    }
    st.push(node);
}


void reverseDfs(vector<int> transpose[], vector<int> &visited, int node)
{
    visited[node] = 1;
    for (auto it : transpose[node])
    {
        if (!visited[it])
            reverseDfs(transpose, visited, it);
    }
}


//Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<int> adj[])
{
    //code here
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(adj, visited, st, i);
    }

    vector<int> transpose[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        for (auto it : adj[i])
            transpose[it].push_back(i);
    }

    int count = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            count++;
            reverseDfs(transpose, visited, node);
        }
    }
    return count;
}