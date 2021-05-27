//time O(n^2)
int maxArea(vector<int>& height)
{
	int maxi = 0;
	int leftmax = -1, rightmax = height.size();
	for (int i = 0; i < height.size(); i++)
	{
		leftmax = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (height[j] >= height[i])
				leftmax = j;
		}
		rightmax = i;
		for (int j = i + 1; j < height.size(); j++)
		{
			if (height[j] >= height[i])
				rightmax = j;
		}
		maxi = max(maxi, (rightmax - leftmax) * height[i]);
	}
	return maxi;
}


//***************************************************************
//Time O(n), using two pointer algo
int maxArea(vector<int>& height)
{
	int maxWater = 0;
	int left = 0, right = height.size() - 1;
	while (left < right)
	{
		maxWater = max(maxWater, (right - left) * min(height[left], height[right]));
		if (height[left] < height[right])
			left++;
		else
			right--;
	}
	return maxWater;
}