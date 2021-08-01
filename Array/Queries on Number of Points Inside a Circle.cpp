vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
{

    vector<int> result;
    for (auto q : queries)
    {
        int count = 0;
        for (auto p : points)
        {
            if ((pow(q[0] - p[0], 2) + pow(q[1] - p[1], 2)) <= pow(q[2], 2))
                count++;
        }
        result.push_back(count);
    }
    return result;
}