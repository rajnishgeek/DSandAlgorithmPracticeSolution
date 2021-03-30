#include<bits/stdc++.h>
using namespace std;
int dp[100];

int minCost(int a[], int i, int n)
{
    if(i<0)
        return INT_MAX;
    if(i==0)
    {
        dp[i]=0;
        return dp[i];
    }

    if(dp[i]!=-1)
        return dp[i];
    int one=0,two=0;

    if(i-1>=0)
        one=abs(a[i]-a[i-1]);
    one+=minCost(a,i-1,n);
    if(i-2>=0)
        two=abs(a[i]-a[i-2]);
    two+=minCost(a,i-2,n);

    dp[i]=min(one,two);
    return dp[i];

}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<minCost(a,n-1,n)<<endl;
    return 0;
}
