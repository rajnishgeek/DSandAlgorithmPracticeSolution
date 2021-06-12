//my approach, time O(n)
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	bool top = true, bottom = false, left = false, right = false;
	int i = 0, rowstart = 0, rowend = matrix.size() - 1, colstart = 0, colend = matrix[0].size() - 1;
	while (rowstart <= rowend && colstart <= colend)
	{
		if (top)
		{
			res.push_back(matrix[rowstart][i]);
			if (i == colend)
			{
				top = false;
				right = true;
				i = ++rowstart;
			}
			else
				i++;
		}
		else if (right)
		{
			res.push_back(matrix[i][colend]);
			if (i == rowend)
			{
				right = false;
				bottom = true;
				i = --colend;
			}
			else
				i++;
		}
		else if (bottom)
		{
			res.push_back(matrix[rowend][i]);
			if (i == colstart)
			{
				bottom = false;
				left = true;
				i = --rowend;
			}
			else
				i--;
		}
		else if (left)
		{
			res.push_back(matrix[i][colstart]);
			if (i == rowstart)
			{
				left = false;
				top = true;
				i = ++colstart;
			}
			else
				i--;
		}
	}
	return res;
}