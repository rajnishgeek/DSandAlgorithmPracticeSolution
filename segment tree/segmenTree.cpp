#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
this is how build segment tree for min query of given by gfg
ss: starting index
se: ending index
si: current index

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if(ss==se)//rach at leaf node
    {
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid=getmid(ss,se);
    st[si]=minVal(constructSTUtill(arr,ss,mid,st,si*2+1),
      constructSTUtil(arr,mid+1,se,st,si*2+2));
      return st[si];
}
*/
/*this is my code of segment tree build and min query
void constructSThealper(int *a,int *segmenttree,int s,int e,int index)
{
    //rached at leaf node
    if(s==e)
    {
        segmenttree[index]=a[s];
        return;
    }
    
    //recursion call
    int mid= (s+e)/2;
    constructSThealper(a,segmenttree,s,mid,2*index);
    constructSThealper(a,segmenttree,mid+1,e,2*index+1);
    segmenttree[index]=min(segmenttree[2*index],segmenttree[2*index+1]);
    return;
}
int *constructST(int arr[],int n)
{
  //Your code here
  int *segmenttree=new int[4*n+1];
  constructSThealper(arr,segmenttree,0,n-1,1);
  return segmenttree;
}

int RMQhealper(int *st,int qs,int qe,int s,int e,int index)
{
    if (qs <= s && qe >= e)
        return st[index];
    //no overlap
    if(qe<s || qs>e)
     return INT_MAX;
    //partial overlape
    int mid = (s + e) / 2;
    int leftchild = RMQhealper(st, qs, qe, s, mid, 2 * index);
    int rightchid = RMQhealper(st, qs, qe, mid + 1, e, 2 * index + 1);
    return min(leftchild, rightchid);
}
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
  return RMQhealper(st,a,b,0,n-1,1);
}
*/
//this function make segment tree using array
void buildSegmentTree(int *tree, int *a, int s, int e, int treeindex)
{
    //base case
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
    tree[treeindex] = min(leftchild, rightchild);
    return;
}

//this function return the minimum element of given query range
int queryMin(int *tree, int qs, int qe, int stree, int etree, int nodeindex)
{
    //total overlape
    if (qs <= stree && qe >= etree)
        return tree[nodeindex];
    //no overlape
    if (qe < stree || qs > etree)
        return INT_MAX;

    //partial overlape
    int mid = (stree + etree) / 2;
    int leftchild = queryMin(tree, qs, qe, stree, mid, 2 * nodeindex);
    int rightchid = queryMin(tree, qs, qe, mid + 1, etree, 2 * nodeindex + 1);
    return min(leftchild, rightchid);
}

//this function is for updation of single node
void updateSingleNode(int *tree, int s, int e, int treeindex, int index, int value)
{
    //no overlap
    if (index < s || index > e)
        return;

    //reached at leaf node
    if (s == e) //if(treeindex==s && e==treeindex)
    {
        tree[treeindex] = value;
        return;
    }

    //partial overlap means index value lyping between s and e
    int mid = (s + e) / 2;
    updateSingleNode(tree, s, mid, 2 * treeindex, index, value);
    updateSingleNode(tree, mid + 1, e, 2 * treeindex + 1, index, value);
    tree[treeindex] = min(tree[2 * treeindex], tree[2 * treeindex + 1]);
    return;
}
//update the whole range value
void updateRange(int *tree, int qs, int qe, int s, int e, int treeindex, int value)
{
    //no overlap
    if (qe < s || qs > e)
        return;

    //reached at leaf node
    if (s == e)
    {
        tree[treeindex] += value;
        return;
    }

    //laying between s and e
    int mid = (s + e) / 2;
    updateRange(tree, qs, qe, s, mid, 2 * treeindex, value);
    updateRange(tree, qs, qe, mid + 1, e, 2 * treeindex + 1, value);
    tree[treeindex] = min(tree[2 * treeindex], tree[2 * treeindex + 1]);
    return;
}
int main()
{
    int a[] = (3, -3, 4, 5, 1);
    int n = sizeof(a) / sizeof(int);
    int *segmenttree = new int[4 * n + 1];
    int s = 0, e = n - 1, treeindex = 1;
    buildSegmentTree(segmenttree, a, s, e, treeindex);
    int no_of_q;
    cin >> no_of_q;
    while (no_of_q)
    {
        int qs, qe;
        cin >> qs >> qe;
        cout << "the minimum value of given range is :- ";
        cout << queryMin(segmenttree, qs, qe, s, e, treeindex);
    }
    int index, value;
    cout << "enter index and value for single node updation";
    cout << "enter index :- ";
    cin >> index;
    cout << "enter value :- ";
    cin >> value;
    updateSingleNode(segmenttree, s, e, treeindex, index, value);

    cout << "enter no. of queries for whole range upadation :- ";
    cin >> no_of_q;
    while (no_of_q)
    {
        int qs, qe;
        cin >> qs >> qe;
        int inc;
        cout << "enter the increment value you want to increment :- ";
        cin >> inc;
        updateRange(segmenttree, qs, qe, s, e, treeindex, inc);
    }
    delete segmenttree;
}
