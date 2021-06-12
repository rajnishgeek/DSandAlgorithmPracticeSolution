vector<vector<int>> result;

bool isSafe(vector<vector<int>> board, int row, int col)
{
    int i, j;
    int N = board.size();
    for (j = 0; j < col; j++)
        if (board[row][j] == 1)
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;
    return true;
}

bool NQueen(vector<vector<int>> &board, int col)
{
    int N = board.size();
    if (col == N)
    {
        vector<string> v;
        for (int i = 0; i < N; i++)
        {
            string s;
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                    s.push_back('Q');
                else
                    s.push_back('.');
            }
            v.push_back(s);
        }
        result.push_back(v);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            res = NQueen(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

vector<vector<string>> solveNQeens(int n)
{
    result.clear();
    vector<vector<int>> board(n, vector<int> (n, 0));
    if (NQeen(board, 0) == false)
        return result;
    return result;
}