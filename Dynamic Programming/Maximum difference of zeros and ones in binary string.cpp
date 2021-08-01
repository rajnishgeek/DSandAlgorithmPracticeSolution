int maxSubstring(string S)
{
	// Your code goes here
	int result = -1;
	int maximum = 0;
	for (int i = 0; i < S.size(); i++)
	{
		maximum += (S[i] == '0') ? 1 : -1;
		if (result < maximum)
			result = maximum;
		if (maximum < 0)
			maximum = 0;
	}
	return result;
}