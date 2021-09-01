int findNumberOfLIS(vector<int>& nums)
{
    int n = nums.size(), maxLen = 1, result = 0;
    vector<int> len(n, 1), counts(n, 1);
    for (int i = 0; i < n; i++)
    {
        int maximum = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (len[j] + 1 > len[i])
                {
                    counts[i] = counts[j];
                    len[i] = len[j] + 1;
                }
                else if (len[j] + 1 == len[i])
                {
                    counts[i] += counts[j];
                }
            }
        }
        maxLen = max(maxLen, len[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (len[i] == maxLen)
            result += counts[i];
    }

    return result;
}