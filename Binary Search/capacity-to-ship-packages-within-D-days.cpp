int shipWithinDays(vector<int>& weights, int days) 
    {
        int left=0, right=0;
        for(int i=0;i<weights.size();i++)
        {
            left=max(left, weights[i]);
            right+=weights[i];
        }
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            int min_day=1, curr_sum=0;
            for(int i=0;i<weights.size() && min_day<=days;i++)
            {
                if(curr_sum+weights[i]>mid)
                {
                    curr_sum=0;
                    min_day++;
                }
                curr_sum+=weights[i];
            }
            if(min_day>days)
                left=mid+1;
            else
                right=mid;
                
        }
        return left;   
    }