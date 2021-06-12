//time O(nLogn), space O(n)
void wiggleSort(vector<int>& nums)
{
    vector<int> arr(nums.begin(), nums.end());
    int idx = nums.size() - 1;
    sort(arr.begin(), arr.end());

    for (int i = 1; i < nums.size(); i += 2)
        nums[i] = arr[idx--];

    for (int i = 0; i < nums.size(); i += 2)
        nums[i] = arr[idx--];
}