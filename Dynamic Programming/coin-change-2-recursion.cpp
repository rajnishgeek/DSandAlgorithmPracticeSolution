//recursion code
int coinChangeRecurrsion(vector<int> &coins, int n, int amount)
    {
        if(amount==0)
            return 0;
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
             if(coins[i]<=amount)
             {
                 int sub_res=coinChangeRecurrsion(coins, n, amount-coins[i]);
                 if(sub_res!=INT_MAX && sub_res+1<res)
                     res=sub_res+1;
             }
        }
       
        return res;
    }

    int coinChange(vector<int>& coins, int amount)
    {
        if(coins.size()==0 || amount==0)
            return 0;
        return coinChangeRecurrsion(coins, coins.size(), amount);
    }