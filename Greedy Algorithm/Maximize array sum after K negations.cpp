int largestSumAfterKNegations(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);
    while (k--)
    {
        int value = pq.top();
        pq.pop();
        value = value * -1;
        pq.push(value);
    }
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}