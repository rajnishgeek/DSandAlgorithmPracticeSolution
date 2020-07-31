#include<bits/stdc++.h>
using namespace std;

int countsOfSubsetSum(int arr[], int n, int sum)
{
	int dp[n+1][sum+1];

	//initialize 0th col with 1 and 0th row with 0 except [0][0]=1
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
				dp[i][j]=0;
			if(j==0)
				dp[i][j]=1;
		}
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			//if we include the array element
			if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            //if we exclude the array element
		    else
		    	dp[i][j]=dp[i-1][j];
		}
	}
    //our result will be stored at [n][sum] cell
	return dp[n][sum];
}
int main()
{
    int arr[]={2,3,5,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=10;
    cout<<countsOfSubsetSum(arr,n,sum)<<endl;
	return 0;
}
