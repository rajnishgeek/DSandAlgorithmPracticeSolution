//recursion code
int waysToDecodeRecursion(string s, int n)
{
	if (n == 0 || n == 1)
		return 1;
	if (s[0] == '0')
		return 0;
	int count = 0;
	if (s[n - 1] > '0')
		count = waysToDecodeRecursion(s, n - 1);
	if (s[n - 2] == '1' || (s[n - 2] == '2' && s[n - 1] < '7'))
		count += waysToDecodeRecursion(s, n - 2);
	return count;
}

int waysToDecode(string s)
{
	if (s.size() == 0 || (s.size() == 1 && s[0] == '0'))
		return 0;
	return waysToDecodeRecursion(s, s.size());
}


//DP code
int waysToDecode(string s)
{
	int n = s.size();
	if (s[0] == '0')
		return 0;
	int count[n + 1];
	count[0] = 1;
	count[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		count[i] = 0;
		if (s[i - 1] > '0')
			count[i] = count[i - 1];
		if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
			count[i] += count[i - 2];
	}
	return count[n];
}