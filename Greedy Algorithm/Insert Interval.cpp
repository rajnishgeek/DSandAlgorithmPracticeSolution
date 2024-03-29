vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> result;
    int n = intervals.size();
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0])
        result.push_back(intervals[i++]);
    //result.push_back(vector<int> {intervals[i][0],intervals[i][1]});

    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
        i++;
    }
    result.push_back(newInterval);

    while (i < n)
        result.push_back(intervals[i++]);
    return result;
}