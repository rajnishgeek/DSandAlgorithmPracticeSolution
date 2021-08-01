int threeSumClosest(vector<int>& nums, int target)
{
    int minClose = nums[0] + nums[1] + nums[2];
    int maxClose = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int start = i + 1, end = nums.size() - 1;
        while (start < end)
        {
            if (nums[i] + nums[start] + nums[end] == target)
                return target;
            else if (nums[i] + nums[start] + nums[end] < target)
            {
                if (nums[i] + nums[start] + nums[end] > minClose)
                    minClose = nums[i] + nums[start] + nums[end];
                start++;
            }
            else if (nums[i] + nums[start] + nums[end] > target)
            {
                if (nums[i] + nums[start] + nums[end] < maxClose)
                    maxClose = nums[i] + nums[start] + nums[end];
                end--;
            }
        }
    }

    return (abs(target - minClose) == abs(maxClose - target)) || (abs(target - minClose) < abs(maxClose - target)) ? minClose : maxClose;
}