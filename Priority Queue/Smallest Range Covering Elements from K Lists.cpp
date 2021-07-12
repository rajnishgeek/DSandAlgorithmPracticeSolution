vector<int> smallestRange(vector<vector<int>>& nums)
{
    int k = nums.size();
    int n = nums[0].size();
    int range = INT_MAX, min = INT_MAX, max = INT_MIN, start, end;
    //first is element,second.first is i,second.second is j
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < k; i++)
    {
        pair<int, pair<int, int>> harr;
        harr.first = nums[i][0];
        harr.second.first = i;
        harr.second.second = 1;
        if (harr.first > max)
            max = harr.first;
        pq.push(harr);
    }

    while (1)
    {
        pair<int, pair<int, int>> root = pq.top();
        pq.pop();
        min = root.first;
        if (range > max - min + 1)
        {
            range = max - min + 1;
            start = min;
            end = max;
        }

        if (root.second.second < n)
        {
            root.first = nums[root.second.first][root.second.second];
            root.second.second += 1;
            if (root.first > max)
                max = root.first;
        }
        else
            break; s
        pq.push(root);
    }
    return vector<int> {start, end};
}