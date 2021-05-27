int reverse(int n)
{
    int sum = 0;
    while (n)
    {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    return sum;
}

int countNicePairs(vector<int>& nums)
{
    int count = 0;
    int mod = pow(10, 9) + 7;
    unordered_map<int, int> freq;

    for (int i = 0; i < nums.size(); i++)
    {
        int diff = nums[i] - reverse(nums[i]);
        if (freq.count(diff))
        {
            count = (count + freq[diff]) % mod;
        }
        ++freq[diff];
    }
    return count;
}