#include <bits/stdc++.h>
using namespace std;

//this function make segment tree using array
void buildSegmentTree(int *tree, int *a, int s, int e, int treeindex)
{
    //reach at leaf node
    if (s == e)
    {
        tree[treeindex] = a[s];
        return;
    }
    //recursion call
    int mid = (s + e) / 2;
    buildSegmentTree(tree, a, s, mid, 2 * treeindex);
    buildSegmentTree(tree, a, mid + 1, e, 2 * treeindex + 1);
    int leftchild = tree[2 * treeindex];
    int rightchild = tree[2 * treeindex + 1];
    tree[treeindex] = (leftchild + rightchild);
    return;
}

//this function return the minimum element of given query range
int queryMax(int *tree, int qs, int qe, int stree, int etree, int nodeindex)
{
    //no overlape
    if (qe < stree || qs > etree)
        return 0;

    //total overlape
    if (qs <= stree && qe >= etree)
        return tree[nodeindex];

    //partial overlape
    int mid = (stree + etree) / 2;
    int leftchild = queryMax(tree, qs, qe, stree, mid, 2 * nodeindex);
    int rightchid = queryMax(tree, qs, qe, mid + 1, etree, 2 * nodeindex + 1);
    return (leftchild + rightchid);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *segmenttree = new int[4 * n + 1];
    buildSegmentTree(segmenttree, a, 0, n - 1, 1);
    int m;
    cin >> m;
    int querymax[m];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        querymax[i] = queryMax(segmenttree, x, y, 0, n - 1, 1);
    }
    for (int i = 0; i < m; i++)
        cout << querymax[i] << endl;
    return 0;
}
