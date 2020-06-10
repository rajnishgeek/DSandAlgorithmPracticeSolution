#include<bits/stdc++.h>
using namespace std;
//fuction for edding edge and weioght
void addEdgeAndWeight(vector<pair<int,int>> adj[], int start, int dest, int weight)
{
    adj[start].push_back(make_pair(dest,weight));
    adj[dest].push_back(make_pair(start,weight));
}
//function for printing graph sequentially
void pritWeightedGraphSequentilly(vector<pair<int ,int >> adj, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"adjacent vertex and weight of "<<i<<" vertex :"
        for()
    }
}
int main()
{
    int n=5;
    vector<pair<int, int>> vertex[n];
    addEdgeAndWeight(vertex, 0, 1, 10);
    addEdgeAndWeight(vertex, 0, 4, 20);
    addEdgeAndWeight(vertex, 1, 2, 30);
    addEdgeAndWeight(vertex, 1, 3, 40);
    addEdgeAndWeight(vertex, 1, 4, 50);
    addEdgeAndWeight(vertex, 2, 3, 60);
    addEdgeAndWeight(vertex, 3, 4, 70);
    pritWeightedGraphSequentilly(vertex,n);

    return 0;
}
