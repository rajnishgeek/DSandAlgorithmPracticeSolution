int maximalRectangle(vector<vector<char>>& matrix)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size();

    //converting binary char matrix into binary int matrix for simplicity
    vector<vector<int>> mat(m + 1, vector<int> (n));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j] = matrix[i - 1][j] == '1' ? 1 : 0;
    }

    vector<vector<int>> dp(m + 1, vector<int> (n));

    int mx = 0;
    for (int i = 1; i <= m; i++)
    {
        //find left limit
        int leftBound = -1;
        stack<int> st;
        vector<int> left(n);
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                mat[i][j] = 1 + mat[i - 1][j];
                while (!st.empty() && mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = leftBound;
                if (!st.empty())
                    val = max(val, st.top());

                left[j] = val;
            }
            else
            {
                leftBound = j;
                left[j] = 0;
            }
            st.push(j);
        }

        //clear stack
        while (!st.empty())
            st.pop();

        //fing right limit
        int rightBound = n;
        for (int j = n - 1; j >= 0; j--)
        {
            if (mat[i][j] == 1)
            {
                while (!st.empty() && mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = rightBound;
                if (!st.empty())
                    val = min(val, st.top());

                dp[i][j] = mat[i][j] * ((val - 1) - (left[j] + 1) + 1);
                mx = max(mx, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
                rightBound = j;
            }
            st.push(j);
        }
    }
    return mx;
}