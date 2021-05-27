int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    unordered_map<int , int> m;
    int n = nums1.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ++m[nums1[i] + nums2[j]];

    //apply a+b+c+d=0
    //so c+d=0-(a+b)
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (m.count(0 - (nums3[i] + nums4[j])))
                count += m[0 - (nums3[i] + nums4[j])];
    return count;
}