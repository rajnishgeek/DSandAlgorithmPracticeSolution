int lengthOfLIS(vector<int>& nums)
    {
        int maxLen=0, n=nums.size();
        int dp[n];
        memset(dp, 0, sizeof dp);
        for(int i=0;i<n;i++)
        {
            int maximum=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[j]>maximum)
                        maximum=dp[j];
                }
            }
            dp[i]=maximum+1;
            maxLen=max(maxLen, dp[i]);
        }
        return maxLen;
    }