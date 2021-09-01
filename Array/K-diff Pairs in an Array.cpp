int findPairs(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && i < nums.size() && nums[i - 1] == nums[i])
        {
            while (i < nums.size() && nums[i - 1] == nums[i])
                i++;
            if (i >= nums.size())
                return count;
        }
        int find = k + nums[i];
        int start = i + 1, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == find)
            {
                count++;
                break;
            }
            else if (find < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

    }
    return count;
}