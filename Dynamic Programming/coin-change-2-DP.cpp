int coinChange(vector<int>& coins, int amount)
    {
        int dp[amount+1];
        for(int i=0;i<amount+1;i++)
            dp[i]=INT_MAX;
        dp[0]=0;
        for(int i=1;i<amount+1;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(coins[j]<=i)
                {
                    int sub_res=dp[i-coins[j]];
                    if(sub_res!=INT_MAX && sub_res+1<dp[i])
                        dp[i]=sub_res+1;
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }