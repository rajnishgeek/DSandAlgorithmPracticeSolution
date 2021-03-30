#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string s, int i, int j)
{
	if (i >= j)
		return true;
	for (; i < j; i++, j--)
		if (s[i] != s[j])
			return false;

	return true;
}
int palindromPartitioningMemo(string s, int i, int j)
{
	if ((i >= j) || isPalindrome(s, i, j))
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];

	int minpartition = INT_MAX;
	for (int k = i; k <= j - 1; k++)
	{
		//int ans = 1 + palindromPartitioningMemo(s, i, k) + palindromPartitioningMemo(s, k + 1, j);
		int left=0;
		if (dp[i][k] != -1)
			left = dp[i][k];
		else
		{
			left = palindromPartitioningMemo(s, i, k);
			dp[i][k] = left;
		}
		int right=0;
		if (dp[k + 1][j] != -1)
			right = dp[k + 1][j];
		else
		{
			right = palindromPartitioningMemo(s, k + 1, j);
			dp[k + 1][j] = right;
		}
		int ans = 1 + left + right;
		if (minpartition < ans)
			minpartition = ans;
	}
	dp[i][j] = minpartition;
	return minpartition;
}
int main()
{
	string s = "nitik";
	memset(dp, -1, sizeof(dp));
	cout << palindromPartitioningMemo(s, 0, s.size()) << endl;
	return 0;
}
