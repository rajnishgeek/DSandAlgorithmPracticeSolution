    int robHelper(vector<int>& nums, int start, int end)
    {

        int previous1=0, previous2=0;
        for(int i=start;i<=end;i++)
        {
            int temp=previous1;
            previous1=max(previous1, previous2+nums[i]);
            previous2=temp;
        }
        return previous1;
    }

    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }