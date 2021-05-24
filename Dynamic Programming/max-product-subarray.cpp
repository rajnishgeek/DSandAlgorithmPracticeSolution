int maxProductSubarray(vector<int> &nums)
{
	int ans = nums[0];
	// imax/imin stores the max/min product of
	// subarray that ends with the current number A[i]

	for (int i = 1, maximum = ans, minimum = ans; i < nums.size(); i++)
	{
		// multiplied by a negative makes big number smaller, small number bigger
		// so we redefine the extremums by swapping them

		if (nums[i] < 0)
			swap(maximum, minimum);

		maximum = max(nums[i], nums[i] * maximum);
		minimum = min(nums[i], nums[i] * minimum);

		// the newly computed max value is a candidate for our global result
		ans = max(ans, maximum);
	}
	return ans;
}