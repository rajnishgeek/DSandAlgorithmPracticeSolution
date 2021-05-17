#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int previous1=0, previous2=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=previous1;
            previous1=max(previous1, previous2+nums[i]);
            previous2=temp;
        }
        return previous1;
    }
int main()
{
    vector<int> nums= {1,2,3,1};
    cout<<maxProfit(nums, nums.size()-1, nums.size()+1)<<endl;
    return 0;
}
