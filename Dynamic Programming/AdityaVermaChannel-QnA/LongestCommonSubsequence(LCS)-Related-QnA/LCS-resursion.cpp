#include<bits/stdc++.h>
using namespace std;

int longestCommomSubsequenceLength(string x, string y, int m, int n)
{
	//base case
	//if one of string is empty i.e one of string has size 0 so, return 0
	//because common subsequence will be 0
	if (m == 0 || n == 0)
		return 0;

	//if the char matched in both the string
	//then call for next char and plus one because we found one char matched
	if (x[m - 1] == y[n - 1])
		return 1 + longestCommomSubsequenceLength(x, y, m - 1, n - 1);
	//if our char not matched
	//then two condition occur,first take x string whole and y string size less one
	//second take x string size less by one and y string whole
	else
		return max(longestCommomSubsequenceLength(x, y, m, n - 1), longestCommomSubsequenceLength(x, y, m - 1, n));
}
int main()
{
	string x = "abcdgh", y = "abedfhr";
	cout << longestCommomSubsequenceLength(x, y, x.size(), y.size()) << endl;
	return 0;
}