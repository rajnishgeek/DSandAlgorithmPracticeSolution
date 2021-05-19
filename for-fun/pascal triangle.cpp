vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    vector<int> v = {1};
    res.push_back(v);
    if (numRows == 1)
        return res;
    for (int i = 0; i < numRows - 1; i++)
    {
        vector<int> v(1, 1);
        for (int j = 0; j < res[i].size() - 1; j++)
            v.push_back(res[i][j] + res[i][j + 1]);
        v.push_back(1);
        res.push_back(v);
    }
    return res;
}