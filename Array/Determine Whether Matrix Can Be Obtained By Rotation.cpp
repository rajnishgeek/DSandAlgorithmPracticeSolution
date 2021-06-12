bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
{
    bool flag = true;
    for (int k = 0; k < 4; k++)
    {
        int m = mat.size();
        int n = mat[0].size();
        int p = target.size();
        int q = target[0].size();
        if (m != p && n != q)
            continue;
        reverse(mat.begin(), mat.end());
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < n; j++)
                swap(mat[i][j], mat[j][i]);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j])
                    flag = false;
            }
        }
        if (flag == true)
            return flag;
    }
    return flag;
}