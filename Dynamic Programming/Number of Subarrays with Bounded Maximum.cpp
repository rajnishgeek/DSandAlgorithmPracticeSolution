long countSubarray(long n)
{
    return n * (n + 1) / 2;
}
int numSubarrayBoundedMax(vector<int>& nums, int left, int right)
{
    int result = 0, inclusive = 0, exclusive = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < left)
        {
            inclusive++;
            exclusive++;
        }
        else if (nums[i] > right)
        {
            result += countSubarray(inclusive) - countSubarray(exclusive);
            exclusive = 0;
            inclusive = 0;
        }
        else if (nums[i] >= left && nums[i] <= right)
        {
            result -= countSubarray(exclusive);
            inclusive++;
            exclusive = 0;
        }
    }
    result += countSubarray(inclusive) - countSubarray(exclusive);
    return result;
}