int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        m.insert(make_pair(0,1));
        int curr_sum=0, count=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            if(m.count(curr_sum-k))
                count+=m[curr_sum-k];
            m[curr_sum]++;
        }
        return count;
    }