#include<bits/stdc++.h>
using namespace std;

int minCoinsNeededDp(int coins[], int n, int sum)
{
	int dp[n+1][sum+1];

	//initialize 0th col with 1 and 0th row with 0 except [0][0]=1
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			//initializing all element of 0th row with INT_MAX-1
			//because mathmatically if we have empty array so we need infinity coins
			//to make equal to any number
			if(i==0)
				dp[i][j]=INT_MAX-1;

            //initialize 0th col with 0 except [0][0] cell
            // why 0? because array has the elements but sum value is 0
            //so we need 0 coins to make sum equal to 0
			if(j==0 && i!=0)
				dp[i][j]=0;
		}
	}

    //initializing the 1th row because it works differentlly
    for(int j=1;j<sum+1;j++)
    {
    	if(j%coins[0]==0)
    		dp[1][j]=j/coins[0];
    	else
    		dp[1][j]=INT_MAX-1;
    }

	for(int i=2;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			//if we include the array element
			if(coins[i-1]<=j)
				dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
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
    int coins[]={1,2,3};
    int n=sizeof(coins)/sizeof(coins[0]);
    int sum=5;
    cout<<minCoinsNeededDp(coins,n,sum)<<endl;
	return 0;
}
