int zzis(int arr[], int n)
{

	/*las[i][0] = Length of the longest
	    alternating subsequence ending at
	    index i and last element is greater
	    than its previous element
	las[i][1] = Length of the longest
	    alternating subsequence ending
	    at index i and last element is
	    smaller than its previous element */
	int las[n][2];

	// Initialize all values from 1
	for (int i = 0; i < n; i++)
		las[i][0] = las[i][1] = 1;

	// Initialize result
	int res = 1;

	// Compute values in bottom up manner
	for (int i = 1; i < n; i++)
	{

		// Consider all elements as
		// previous of arr[i]
		for (int j = 0; j < i; j++)
		{

			// If arr[i] is greater, then
			// check with las[j][1]
			if (arr[j] < arr[i] &&
			        las[i][0] < las[j][1] + 1)
				las[i][0] = las[j][1] + 1;

			// If arr[i] is smaller, then
			// check with las[j][0]
			if (arr[j] > arr[i] &&
			        las[i][1] < las[j][0] + 1)
				las[i][1] = las[j][0] + 1;
		}

		// Pick maximum of both values at index i
		if (res < max(las[i][0], las[i][1]))
			res = max(las[i][0], las[i][1]);
	}
	return res;
}


/////////////////////////////////////////////////////////////////////////
//time O(n), space O(1)
int AlternatingaMaxLength(vector<int>&nums)
{
	// Code here
	int increasing = 1, decreasing = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] < nums[i])
			increasing = decreasing + 1;
		else if (nums[i - 1] > nums[i])
			decreasing = increasing + 1;
	}
	return max(increasing, decreasing);
}