//time O(nLogn)
int findUnsortedSubarray(vector<int>& nums)
{
	vector<int> temp = nums;
	sort(temp.begin(), temp.end());
	int i = 0, j = nums.size() - 1;
	while ((nums[i] == temp[i] || nums[j] == temp[j]) && i < j)
	{
		if (nums[i] == temp[i])
			i++;
		if (nums[j] == temp[j])
			j--;
	}
	return i == j ? 0 : j - i + 1;
}

//time O(N), space O(1)
int findUnsortedSubarray(vector<int>& nums)
{
	int minimum = INT_MAX, maximum = INT_MIN;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] > nums[i])
			minimum = min(minimum, nums[i]);
	}

	for (int i = nums.size() - 2; i >= 0; i--)
	{
		if (nums[i + 1] < nums[i])
			maximum = max(maximum, nums[i]);
	}

	if (minimum == INT_MAX && maximum == INT_MIN)
		return 0;

	int start = 0, end = nums.size() - 1;
	for (; start < nums.size(); start++)
	{
		if (nums[start] > minimum)
			break;
	}

	for (; end >= 0; end--)
	{
		if (nums[end] < maximum)
			break;
	}
	return end - start + 1;
}

//more optimize code
//time O(N), space O(1)
int findUnsortedSubarray(vector<int>& nums)
{
	int minimum = nums[nums.size() - 1], maximum = nums[0];
	int start = -1, end = -2;
	for (int i = 1; i < nums.size(); i++)
	{
		maximum = max(maximum, nums[i]);
		minimum = min(minimum, nums[nums.size() - 1 - i]);
		if (nums[i] < maximum)
			end = i;
		if (nums[nums.size() - 1 - i] > minimum)
			start = nums.size() - 1 - i;
	}
	return end - start + 1;
}