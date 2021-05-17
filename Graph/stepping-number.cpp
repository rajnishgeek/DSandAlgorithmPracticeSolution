void bfs(int num, int n, int m, vector<int> &res)
{
	queue<int> q;
	q.push(num);
	while (!q.empty())
	{
		int stepNum = q.front();
		q.pop();

		if (n <= stepNum && stepNum <= m)
			res.push_back(stepNum);

		if (num == 0 || stepNum > m)
			continue;

		int lastDigit = stepNum % 10;

		int stepNumA = stepNum * 10 + (lastDigit - 1);
		int stepNumB = stepNum * 10 + (lastDigit + 1);

		if (lastDigit == 0)
			q.push(stepNumB);
		else if (lastDigit == 9)
			q.push(stepNumA);
		else
		{
			q.push(stepNumA);
			q.push(stepNumB);
		}
	}
}

vector<int> steppingNumber(int n, int m)
{
	vector<int> res;
	for (int i = 0; i <= 9; i++)
		bfs(i, n, m, res);
	sort(res.begin(), res.end());
	return res;
}