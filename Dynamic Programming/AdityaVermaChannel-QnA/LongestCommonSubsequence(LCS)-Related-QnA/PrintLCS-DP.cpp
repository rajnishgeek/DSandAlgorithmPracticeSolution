#include<bits/stdc++.h>
using namespace std;

void printLCS(string x, string y, int m, int n)
{
	int dp[m + 1][n + 1];
	//initialize 0th row and column with 0
	for (int i = 0; i < m + 1; i++)
	  for (int j = 0; j < n + 1; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;


	//this will make LCS table
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string result = "";
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (x[i - 1] == y[j - 1])
		{
			result.push_back(x[i - 1]);
			i--;
			j--;
		}
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;
		}
	}

	reverse(result.begin(), result.end());
	cout << result << endl;

}
int main()
{
	string x = "acbcf", y = "abcdaf";
	printLCS(x, y, x.size(), y.size());
	return 0;
}
