int count;

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int i, j;
    int N = board.size();
    for (j = 0; j < col; j++)
        if (board[row][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (i = row , j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;
    return true;
}

bool NQeen(vector<vector<int>> &board, int col)
{
    int N = board.size();
    if (col == N)
    {
        count++;
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            res = NQeen(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

int totalNQueens(int n)
{
    count = 0;
    vector<vector<int>> board(n, vector<int> (n, 0));
    if (NQeen(board, 0) == false)
        return count;
    return count;
}