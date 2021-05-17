int mod(string t, int n)
{
	int rem = 0;
	for (int i = 0; i < t.size(); i++)
	{
		rem = rem * 10 + (t[i] - '0');
		rem %= n;
	}
	rem;
}

string smallestMultiple(int n)
{
	if (n == 0)
		return "0";
	queue<string> q;
	set<int> visited;
	string t = "1";
	q.push(t);
	while (!q.empty())
	{
		t = q.top();
		q.pop();
		int rem = mod(t, n);
		if (rem == 0)
			return t;
		if (visited.count(rem))
		{
			visited.insert(rem);
			q.push(t + "0");
			q.push(t + "1");
		}
	}
	return "";
}