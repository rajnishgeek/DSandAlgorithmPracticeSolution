/*
Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 10 4 2 1]

Return value 6

*/
in longestSubsequenceLength(const vector<int> &A)
{
	int n = A.size();
	vector<int> lis(n, 1), lds(n, 1);

	//storing longest increasing subsecquenc for left to right
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && lis[j] + 1 > lis[i])
				lis[i] = lis[j] + 1;
		}
	}

	//storing longest decreaseing subsequence
	//so we can calculate longest decreasing subsequence by assuming that calclutaing
	//that longest increasing subsequence from right to left
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (A[j] < A[i] && lds[j] + 1 > lds[i])
				lds[i] = lds[j] + 1;
		}
	}

	int len = 0;
	for (int i = 0; i < n; i++)
		len = max(len, lis[i] + lds[i] - 1);

	return len;
}