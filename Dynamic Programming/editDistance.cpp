#include<bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2, int len1, int len2)
{
	//creating table to store min operations
	int dp[len1 + 1][len2 + 1];

	//filling dp in bottom up manner
	for (int i = 0; i < len1 + 1; i++)
	{
		for (int j = 0; j < len2 + 1; j++)
		{
			//this case is for first string is empty,
			//the only option is to insert all char of string 2
			if (i == 0)
				dp[i][j] = j;

			//this case is for string 2 is empty,
			// only option is remove all char of string 1
			else if (j == 0)
				dp[i][j] = i;

			//if last char of both string is same, so no operation need
			// ignore last char and recure for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j] = 1 + min(dp[i - 1][j],//remove
				                   min(dp[i][j - 1],//insert
				                       dp[i - 1][j - 1]));//replace
		}
	}
	return dp[len1][len2];
}

int main()
{
	string str1 = "sunday";
	string str2 = "saturday";
	cout << editDistance(str1, str2, str1.size(), str2.size()) << endl;
	return 0;
}
