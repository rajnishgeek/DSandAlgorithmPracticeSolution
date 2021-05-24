/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/

//this solution take O(n^2) time, O(n) space;
bool isJumpPossible(vector<int> &nums)
{
	int n = nums.size();
	vector<bool> path(n, false);
	path[n - 1] = true;
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < nums[i]; j++)
		{
			if (path[i + j + 1] == true)
			{
				path[i] = true;
				break;
			}
		}
	}
	return path[0];
}


//EFFICIENT SOLUTION, time O(n)
bool path(vector<int> &nums)
{
	int i = 0;
	for (int reach = 0; i < nums.size() && i <= reach; i++)
		reach = max(nums[i] + i, reach);
	return i == nums.size();
}