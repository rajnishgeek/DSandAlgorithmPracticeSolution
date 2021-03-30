#include<bits/stdc++.h>
using namespace std;

int palindromPartitioningRecursion(string s, int i, int j)
{
	if (i >= j)
		return 0;
	int minpartition = INT_MAX;
	for (int k = i; k <= s.size() - 1; k++)
	{
		int ans = 1 + palindromPartitioningRecursion(s, i, k) + palindromPartitioningRecursion(s, k + 1, j);
		if (ans < minpartition)
			minpartition = ans;
	}
	return minpartition;
}
int main()
{
	string s = "nitik";
	cout << palindromPartitioningRecursion(string s, 0, s.size()) << endl;
	return 0;
}