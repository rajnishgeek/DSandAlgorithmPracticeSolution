//time O(NLogN)
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    //first is absolute difference, second is index
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pq.size() < k)
            pq.push(make_pair(abs(arr[i] - x), i));
        else if (pq.size() == k)
        {
            if (abs(arr[i] - x) < pq.top().first)
            {
                pq.pop();
                pq.push({abs(arr[i] - x), i});
            }
        }
    }
    vector<int> res(k);
    for (int i = k - 1; i >= 0; i--)
    {
        res[i] = arr[pq.top().second];
        pq.pop();
    }
    sort(res.begin(), res.end());
    return res;
}

//**************************************************************************
//time O(Log(N-K))
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    int left = 0, right = arr.size() - k;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }
    return vector<int> (arr.begin() + left, arr.begin() + left + k);
}