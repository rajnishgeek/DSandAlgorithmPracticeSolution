void solve(int k, int n, vector<vector<int>> &result, vector<int> values)
{
    if (n == 0 && values.size() == k)
    {
        result.push_back(values);
        return;
    }
    if (values.size() < k)
    {
        for (int i = values.empty() ? 1 : values[values.size() - 1] + 1; i <= 9; i++)
        {
            values.push_back(i);
            solve(k, n - i, result, values);
            values.pop_back();
        }
    }

}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> result;
    solve(k, n, result, vector<int> {});
    return result;
}