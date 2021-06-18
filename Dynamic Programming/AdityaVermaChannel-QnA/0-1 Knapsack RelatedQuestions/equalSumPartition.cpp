#include<bits/stdc++.h>
using namespace std;

bool subsetSumDp(int arr[], int n, int sum)
{
	int dp[n + 1][sum + 1];

	//initialize 0th col with true and 0th row with false except dp[0][0] is true
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
				dp[i][j] = false;
			if (j == 0)
				dp[i][j] = true;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	//our final result will be stored at nth row and sumth col
	return dp[n][sum];
}
bool isEqualSumPartitionPossible(int arr[], int n)
{
	//calculate the total sum of given array
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	//check if given array sum is odd the equal partition is not possible
	if (sum % 2 != 0)
		return false;

	//if given array sum is even the can be possible
	//pass the half value of sum because we only need to find half sum value
	//subset is possible or not. if found then other half sum array will be already possible
	return subsetSumDp(arr, n, sum / 2);
}
int main()
{
	int arr[] = {1, 5, 11, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	isEqualSumPartitionPossible(arr, n) ? cout << "Yes, it is possible" << endl : cout << "No, not possible" << endl;
	return 0;
}
