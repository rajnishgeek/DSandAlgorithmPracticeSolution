#include<bits/stdc++.h>
using namespace std;

int knapsackDp(int weight[], int value[], int n, int W)
{
	int dp[n+1][W+1];
	memset(dp,-1,sizeof(dp));

	//base case become initialization
	//intialize all 0th col value with 0
	//intialize all 0th row value with 0
	for(int i=0;i<n+1;i++)
	  for(int j=0;j<W+1;j++)
		if(i==0 || j==0)
			dp[i][j]=0;

    //filling the values in our dp
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<W+1;j++)
		{
			if(weight[i-1]<=j)
				dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);

			else if(weight[i-1]>j)
				dp[i][j]=dp[i-1][j];
		}
	}

	return dp[n][W];
}
int main()
{
	int weight[]={1,3,4,5},value[]={1,4,5,7};
    int n=sizeof(weight)/sizeof(weight[0]);
    int W=7;
    cout<<knapsackDp(weight,value,n,W)<<endl;
	return 0;
}
