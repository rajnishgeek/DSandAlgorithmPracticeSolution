int findMaxSum(int *arr, int n)
{
	// code here
	if (n == 1)
		return arr[0];

	int include = arr[0];
	int exclude = 0;
	int max_sum;
	for (int i = 1; i < n; i++)
	{
		max_sum = max(include, exclude);
		include = exclude + arr[i];
		exclude = max_sum;
	}
	return max(include, exclude);
}