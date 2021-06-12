unordered_map<string, int> m;
int ways(vector<int> &nums, int index, int currSum, int target)
{
    if (index < 0)
        return currSum == target ? 1 : 0;

    string key = to_string(index) + "_" + to_string(currSum);
    if (m.count(key))
        return m[key];

    return m[key] = ways(nums, index - 1, currSum + nums[index], target) + ways(nums, index - 1, currSum - nums[index], target);
}
int findTargetSumWays(vector<int>& nums, int target)
{
    if (nums.size() == 0)
        return 0;
    m.clear();
    return ways(nums, nums.size() - 1, 0, target);
}