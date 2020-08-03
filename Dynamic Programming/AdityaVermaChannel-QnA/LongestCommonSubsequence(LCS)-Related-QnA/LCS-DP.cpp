#include<bits/stdc++.h>
using namespace std;

int longestCommomSubsequenceLength(string x, string y, int m, int n)
{
	int dp[m + 1][n + 1];

	//set -1 to each cell in our dp array
	memset(dp, -1, sizeof(dp));

	//initialize 0th row and column with 0
	for (int i = 0; i < m + 1; i++)
		for (int j = 0; j < n + 1; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	//fill the rest of our dp array
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			//if the char matched in both the string
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = 0;
		}
	}

	//our final value should be stored at cell [m][n]
	return dp[m][n];
}
int main()
{
	string x = "abcdgh", y = "abedfhr";
	cout << longestCommomSubsequenceLength(x, y, x.size(), y.size()) << endl;
	return 0;
}
