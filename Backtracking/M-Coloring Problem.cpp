bool isSafe(int v, int graph[101][101], int color[], int c, int V)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c = color[i])
            return false;
    }
    return  true;
}

bool graphColoringHelper(int graph[101][101], int m, int color[], int v, int V)
{
    if (v == V )
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c, V))
        {
            color[v] = c;
            if (graphColoringHelper(graph, m, color, v + 1, V))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V];
    memset(color, 0, sizeof color);
    if (graphColoringHelper(graph, m, color, 0, V) == false)
        return false;
    return true;
}

//*************************************************************************************************
class node {
public:
    int color = 1;
    set<int> edges;
};

int canPaint(vector<node> &nodes, int n, int m)
{
    vector<int> visited(n + 1, 0);
    int maxColors = 1;
    for (int sv = 1; sv <= n; sv++)
    {
        if (visited[sv])
            continue;

        visited[sv] = 1;
        queue<int> q;
        q.push(sv);

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto it = nodes[top].edges.begin(); it != nodes[top].edges.end(); it++)
            {
                if (nodes[top].color == nodes[*it].color)
                    nodes[*it].color += 1;
                maxColors = max(maxColors, max(nodes[top].color, nodes[*it].color));
                if (maxColors > m)
                    return 0;

                if (visited[*it] == false)
                {
                    visited[*it] = 1;
                    q.push(*it);
                }
            }
        }
    }
    return 1;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<node> nodes(V + 1);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j])
            {
                nodes[i].edges.insert(i);
                nodes[j].edges.insert(j);
            }
        }
    }

    return canPaint(nodes, V, m);
}