vector<string> res;
int n, m;
void DFS(vector<vector<char>> &board, int row, int col, vector<vector<int>> vis, string word, int index)
{
   if (row < 0 || row >= m || col < 0 || col >= n)
      return;

   if (index >= word.size())
   {
      res.push_back(word);
      return;
   }

   if (board[row][col] != word[index])
      return;

   vis[row][col] = 1;

   DFS(board, row - 1, col, vis, word, index + 1);
   DFS(board, row, col + 1, vis, word, index + 1);
   DFS(board, row + 1, col, vis, word, index + 1);
   DFS(board, row, col - 1, vis, word, index + 1);

   vis[row][col] = 0;
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
   res.clear();
   m = board.size();
   n = board[0].size();
   for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
         for (string word : words)
            if (word[0] == board[i][j])
               DFS(board, i, j, vector<vector<int>> (m, vector<int> (n, 0)), word, 0);
   return res;
}