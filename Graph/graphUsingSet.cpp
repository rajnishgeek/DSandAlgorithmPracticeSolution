#include<bits/stdc++.h>
using namespace std;

//graph structure
struct Graph
{
    int v;
    set<int> *adj;
};

//creating graph
Graph* graphCreation(int n)
{
    Graph *graph = new Graph;
    graph->v = n;
    graph->adj = new set<int>[n];
    return graph;
}

//inserting of edges
void addEdge(Graph *graph, int start, int dest)
{
    graph->adj[start].insert(dest);
    graph->adj[dest].insert(start);
}

//function for printing graph sequentially
void pritGraphSquentially(Graph* graph, int vertexes)
{
    for (int i = 0; i < vertexes; i++)
    {
        set<int> vertex_set = graph->adj[i];
        cout << "adjacent of vertex " << i << " : ";
        for (auto it = vertex_set.begin(); it != vertex_set.end(); it++)
            cout << *it << ", ";
        cout << endl;
    }
}

//searching of edege between given vertex
void searchingEdge(Graph* graph, int start, int dest)
{
    set<int>::iterator vertex_set = graph->adj[start].find(dest);
    if (vertex_set == graph->adj[start].end())
        cout << "edge of " << start << " and " << dest << " not found" << endl;
    else
        cout << "edge of " << start << " and " << dest << " found" << endl;
}

int main()
{
    int vertexes = 5;
    struct Graph *graph = graphCreation(vertexes);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    pritGraphSquentially(graph, vertexes);
    searchingEdge(graph, 1, 2);
    return 0;
}
