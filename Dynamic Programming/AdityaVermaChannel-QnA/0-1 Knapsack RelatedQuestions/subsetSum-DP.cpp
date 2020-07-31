#include<bits/stdc++.h>
using namespace std;

bool subsetSumDp(int arr[], int n,int sum)
{
	int dp[n+1][sum+1];

    //initialize 0th col with true and 0th row with false except dp[0][0] is true
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
				dp[i][j]=false;
			if(j==0)
				dp[i][j]=true;
		}
	}

    for(int i=1;i<n+1;i++)
    {
    	for(int j=1;j<sum+1;j++)
    	{
    		if(arr[i-1]<=j)
    			dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
    		else
    			dp[i][j]=dp[i-1][j];
    	}
    }

    return dp[n][sum];
}
int main()
{
    int arr[]={2,3,7,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=11;
    subsetSumDp(arr,n,sum)?cout<<"Yes, subset possible"<<endl:cout<<"No, subset not possible"<<endl;
	return 0;
}
