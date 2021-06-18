bool canPartitionRecursion(vector<int> &nums, vector<int> &subsetSum, vector<bool> &visited, int targetSum, int k, int n, int currIndex, int limitIndex)
{
    if (subsetSum[currIndex] == targetSum)
    {
        if (currIndex == k - 2)
            return true;
        return canPartitionRecursion(nums, subsetSum, visited, targetSum, k, n, currIndex + 1, n - 1);
    }

    for (int i = limitIndex; i >= 0; i--)
    {
        if (visited[i])
            continue;
        int temp = subsetSum[currIndex] + nums[i];
        if (temp <= targetSum)
        {
            visited[i] = true;
            subsetSum[currIndex] += nums[i];
            bool next = canPartitionRecursion(nums, subsetSum, visited, targetSum, k, n, currIndex, i - 1);
            visited[i] = false;
            subsetSum[currIndex] -= nums[i];
            if (next)
                return true;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
    int n = nums.size();
    if (k == 1)
        return true;
    if (n < k)
        return false;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum % k != 0)
        return false;

    int targetSum = sum / k;
    vector<int> subsetSum(k, 0);
    vector<bool> visited(nums.size(), false);
    subsetSum[0] = nums[n - 1];
    visited[n - 1] = true;
    return canPartitionRecursion(nums, subsetSum, visited, targetSum, k, n, 0, n - 1);
}