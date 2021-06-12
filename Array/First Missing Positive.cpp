int firstMissingPositive(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < n; i++)
        if (nums[i] != i + 1)
            return i + 1;
    return n + 1;
}


//ANOTHER GOOD APPROACH
int firstMissingPositive(vector<int>& nums)
{
    nums.push_back(0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
        if (nums[i] < 0 || nums[i] >= n)
            nums[i] = 0;

    for (int i = 0; i < n; i++)
        nums[nums[i] % n] += n;

    for (int i = 0; i < n; i++)
        if (nums[i] / n == 0)
            return i;
    return n;
}