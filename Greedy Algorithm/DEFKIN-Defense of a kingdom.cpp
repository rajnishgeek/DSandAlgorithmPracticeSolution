#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int w, h, n;
		cin >> w >> h >> n;
		vector<int> row, col;
		row.push_back(0);
		col.push_back(0);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			row.push_back(x);
			col.push_back(y);
		}
		row.push_back(w + 1);
		col.push_back(h + 1);
		sort(row.begin(), row.end());
		sort(col.begin(), col.end());
		int maxWeidth = 0;
		int maxHeight = 0;
		for (int i = 1; i < row.size(); i++)
			maxWeidth = max(maxWeidth, row[i] - row[i - 1] - 1);
		for (int i = 1; i < col.size(); i++)
			maxHeight = max(maxHeight, col[i] - col[i - 1] - 1);
		cout << maxWeidth*maxHeight << endl;
	}
	return 0;
}