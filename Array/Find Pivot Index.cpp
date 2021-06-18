int pivotIndex(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    vector<int> leftSum(n, 0), rightSum(n, 0);
    leftSum[0] = nums[0];
    rightSum[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftSum[i] = leftSum[i - 1] + nums[i];
        rightSum[n - i - 1] = rightSum[n - i] + nums[n - i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (leftSum[i] == rightSum[i])
            return i;
    }
    return -1;
}