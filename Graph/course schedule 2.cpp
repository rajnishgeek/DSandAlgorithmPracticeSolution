bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (checkCycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }
    dfsVis[node] = 0;
    return false;
}

bool isCyclic(int N, vector<int> adj[])
{
    int vis[N], dfsVis[N];
    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);

    for (int i = 0; i < N; i++)
    {
        if (vis[i] == 0)
        {
            if (checkCycle(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}

void findTopoSort(vector<int> adj[], int node, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            findTopoSort(adj, it, vis, st);
        }
    }
    st.push(node);
}


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> adj[numCourses];
    vector<int> res;
    for (int i = 0; i < prerequisites.size(); i++)
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    if (isCyclic(numCourses, adj))
        return res;

    stack<int> st;
    vector<int> vis(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        if (vis[i] == 0)
        {
            findTopoSort(adj, i, vis, st);
        }
    }

    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}