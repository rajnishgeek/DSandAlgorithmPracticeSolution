#include <bits/stdc++.h>
using namespace std;

void pritGraphSequentially(vector<int> adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "adjacent vertex of vertex " << i << ":";
        for (auto v : adj[i])
            cout << "->" << v;
        cout << endl;
    }
}

//function for adding edge in undirected graph
void addEdge(vector<int> adj[], int start, int dest)
{
    adj[start].push_back(dest);
    adj[dest].push_back(start);
}
//healper function of dfs traversal
void DFShealper(vector<bool> &visited, vector<int> adj[], int currvertex)
{
    visited[currvertex] = true;
    cout << currvertex << "->";
    for (int i = 0; i < adj[currvertex].size(); i++)
    {
        if (visited[adj[currvertex][i]] == false)
            DFShealper(visited, adj, adj[currvertex][i]);
    }
}
//function for dfs traversal of graph
void printDFStraversal(vector<int> adj[], int n)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            DFShealper(visited, adj, i);
    }
}
//bfs traversal healper function
/*
void BFShealper(vector<int> adj[],vector<bool> &visited,queue<int> &q, int start)
{
    visited[start]=true;
    cout<<start<<" ";
    for(auto it=adj[start].begin();it!=adj[start].end();it++)
     q.push(*it);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        if(!visited[a])
            BFShealper(adj,visited,q,a);
    }
}
//bfs traversal function
void printBFStraversal(vector<int> adj[], int v, int start)
{
    vector<bool> visited;
    for(int i=0;i<v;i++)
        visited[i]=false;
    queue<int> q;
    for(int i=0;i<v;i++)
     if(visited[i]==false)
        BFShealper(adj,visited,q,start);
}
*/
void printBFS(vector<int> adj[], int n, int s)
{
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
         s=q.front();
        cout<<s<<"->";
        q.pop();
        for(auto it=adj[s].begin();it!=adj[s].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                q.push(*it);
            }
        }

    }
    cout<<endl;
}
//cycle healper function
bool isCycleByDFSHealper(vector<int> adj[],vector<bool> &visited, vector<bool> &s, int i)
{
    if(!visited[i])
    {
        s[i]=true;
        visited[i]=true;
       for(auto it=adj[i].begin();it!=adj[i].end();it++)
       {
          if(!visited[*it] && isCycleByDFSHealper(adj,visited,s,*it))
              return true;
          else if(!s[*it])
            return true;
       }
    }
     s[i]=false;
     return false;
}
//finding cycle function
bool isCycleByDFS(vector<int> adj[],int n)
{
    vector<bool> visited;
    vector<bool> s;
    for(int i=0;i<n;i++)
    {
        visited.push_back(false);
        s.push_back(false);
    }

    for(int i=0;i<n;i++)
    {
        if(isCycleByDFSHealper(adj,visited,s,i))
         return true;
    }
    return false;

}
//function of is cycle by bfs
bool isCycleByBFS(vector<int> adj[], int n)
{
    vector<bool> visited;
    vector<bool> s;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        visited.push_back(false);
        s.push_back(false);
    }
    q.push(0);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        if(!visited[a])
        {
            s[a]=false;
            visited[a]=false;
        }
        for(auto it=adj[a].begin();it!=adj[a].end();it++)
        {
            if(visited[*it] && s[*it])
                return true;
            else if(visited[*it] && !s[*it])
                return false;
            q.push(*it);
        }
    }
    return false;
}
int main()
{
    int n = 5;
    vector<int> arrofvector[n];
    addEdge(arrofvector, 0, 1);
    addEdge(arrofvector, 0, 4);
    addEdge(arrofvector, 1, 2);
    addEdge(arrofvector, 1, 3);
    addEdge(arrofvector, 1, 4);
    addEdge(arrofvector, 2, 3);
    addEdge(arrofvector, 3, 4);
    //pritGraphSequentially(arrofvector,n);
   // printDFStraversal(arrofvector, n);
   // printBFS(arrofvector,n,0);
    //cout<<isCycleByDFS(arrofvector,n)<<endl;
    cout<<isCycleByBFS(arrofvector,n)<<endl;
    return 0;
}
