#include<bits/stdc++.h>
using namespace std;

void subsetSum(int arr[], int n,int sum, vector<int> &v)
{
    bool dp[n+1][sum+1];
    //initialize 0th col true
    //initialize 0th row false
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
    			dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
    		else
    			dp[i][j]=dp[i-1][j];
    	}
    }

    //here we are pushing all the index in last row
    //which is true
    //we are doing this for getting all sums value till half of the our range
    for(int i=0;i<=(sum/2);i++)
      if(dp[n][i])
    	v.push_back(i);

}

//this function return the min difference of any two subset
int minimumSumDifference(int arr[], int n)
{
	//calculate the total sum of array i.e range
	int range=0;
	for(int i=0;i<n;i++)
		range+=arr[i];

	vector<int> sums;
	subsetSum(arr,n,range,sums);

	int minimum=INT_MAX;
	for(int i=0;i<sums.size();i++)
      minimum=min(minimum,range-2*sums[i]);
    return minimum;
}
int main()
{
    int arr[]={1,6,11,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minimumSumDifference(arr,n)<<endl;
	return 0;
}
