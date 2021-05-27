//Time complexity O(nLogn)
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int left = 0, right = matrix[i].size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (matrix[i][middle] == target)
                return true;
            else if (target < matrix[i][middle])
                right = middle - 1;
            else
                left = middle + 1;
        }
    }
    return false;
}

//***************************************************************
//time O(n+m)
/*
We start search the matrix from top right corner,
initialize the current position to top right corner,
if the target is greater than the value in current position,
hen the target can not be in entire row of current position
because the row is sorted, if the target is less than
the value in current position, then the target can not in
the entire column because the column is sorted too.
We can rule out one row or one column each time,
so the time complexity is O(m+n).
*/

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    if (m < 1 || n < 1)
        return false;
    int row = 0, col = n - 1;
    while (row < m && col >= 0)
    {
        if (target == matrix[row][col])
            return true;
        else if (target < matrix[row][col])
            col--;
        else
            row++;
    }
    return false;
}