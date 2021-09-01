vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
//Your code here
    vector<vector<int>> result;
    unordered_set<string> m;
    for (int i = 0; i < row; i++)
    {
        string s = "";
        for (int j = 0; j < col; j++)
            s += to_string(M[i][j]);
        if (m.count(s) == 0)
        {
            m.insert(s);
            vector<int> v;
            for (int j = 0; j < col; j++)
                v.push_back(M[i][j]);
            result.push_back(v);
        }
    }
    return result;
}