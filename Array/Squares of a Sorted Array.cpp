vector<int> sortedSquares(vector<int>& nums)
{
    int n = nums.size();
    vector<int> res(n);
    for (int left = 0, right = n - 1, i = n - 1; i >= 0; i--)
    {
        if (abs(nums[left]) > abs(nums[right]))
            res[i] = nums[left] * nums[left++];
        else
            res[i] = nums[right] * nums[right--];
    }
    return res;
}