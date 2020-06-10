#include<bits/stdc++.h>
using namespace std;

void buildST(int *arr,int *tree, int s, int e, int index)
{
    if(s==e)
    {
        tree[index]=arr[e];
        return;
    }
    int mid=(s+e)/2;
    buildST(arr,tree,s,mid,2*index);
    buildST(arr,tree,mid+1,e,2*index+1);
    tree[index]=tree[2*index]+tree[2*index+1];
    return;
}

int prefixSum(int *tree,int qs,int qe,int s,int e, int index)
{
    //no overlap
    if(qe<s || qs>e)
    return 0;
    //complete overlap
    if(qs<=s && qe>=e)
     return tree[index];

    //recursion call
    int mid=(s+e)/2;
    int left= prefixSum(tree,qs,qe,s,mid,2*index);
    int right=  prefixSum(tree,qs,qe,mid+1,e,2*index+1);
    //tree[index]=left+right;
    return left+right;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int *tree=new int[4*n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    buildST(arr,tree,0,n-1,1);
    int i,j;
    cin>>i>>j;
    cout<<prefixSum(tree,i,j,0,n-1,1)<<endl;
    return 0;
}
