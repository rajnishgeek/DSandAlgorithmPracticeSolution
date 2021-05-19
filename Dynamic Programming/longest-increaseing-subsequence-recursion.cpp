//recursion
int solve(vector<int> &nums, int n, int lastelement)
    {
        if(n<=0)
            return 0;
        int res;
        if(nums[n-1]<lastelement)
            res=max(1+solve(nums, n-1, nums[n-1]),solve(nums, n-1, lastelement));
        else 
            res=solve(nums, n-1, lastelement);
        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
       
        return solve(nums, nums.size(), INT_MAX);
    }