#include<bits/stdc++.h>
using namespace std;


int knapsackHealper(int weight[], int value[], int n, int W, int dp[][])
{
	//base case
	//if our array is null so return 0
	//if our given weight of bag (i.e W ) is 0 so return 0
	if(n==0 || W==0)
		return 0;

    //always check first if our dp array has the required value of not
    //if dp has the value then return the value
	if(dp[n][W]!=-1)
		return dp[n][W];

    //checking here if the weight element is less than or equal to given bag Weight
	//then include the weight
	if(weight[n-1]<=W)
	{
		dp[n][W]=max(value[n-1]+knapsackHealper(weight,value,n-1,W-weight[n-1],dp),knapsackHealper(weight,value,n-1,W,dp));
		return dp[n][W];
	}

    //here checking if our weight element become grater than our Bag value
    //then we not include the current weight element in the bag
	else if(weight[n-1]>W)
	{
		dp[n][W]= knapsackHealper(weight,value,n-1,W,dp);
		return dp[n][W];
	}
}
int knapsack(int weight[], int value[], int n, int W)
{
    int *dp=new int[n+1][W+1];
    memset(dp,-1,sizeof(dp));
    return knapsackHealper(weight,value,n,W,dp);
}
int main()
{
	int weight[]={1,3,4,5},value[]={1,4,5,7};
    int n=sizeof(weight)/sizeof(weight[0]);
    int W=7;
    cout<<knapsack(weight,value,n,W)<<endl;
	return 0;
}
