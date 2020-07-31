#include<bits/stdc++.h>
using namespace std;

int rodCuttingMaxProfitDp(int length[], int price[], int n, int rod_length)
{
	int dp[n+1][rod_length+1];
	memset(dp,-1,sizeof(dp));

	//base case become initialization
	//intialize all 0th col value with 0
	//intialize all 0th row value with 0
	for(int i=0;i<n+1;i++)
	  for(int j=0;j<rod_length+1;j++)
		if(i==0 || j==0)
			dp[i][j]=0;

    //filling the values in our dp
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<rod_length+1;j++)
		{
			if(length[i-1]<=j)
				dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);

			else if(length[i-1]>j)
				dp[i][j]=dp[i-1][j];
		}
	}

	return dp[n][rod_length];
}
int main()
{
	int length[]={1,2,3,4,5,6,7,8},price[]={1,5,8,9,10,15,17,20};
    int n=sizeof(length)/sizeof(length[0]);
    int rod_length=8;
    cout<<rodCuttingMaxProfitDp(length,price,n,rod_length)<<endl;
	return 0;
}
