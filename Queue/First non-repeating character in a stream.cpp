string FirstNonRepeating(string A) {
	// Code here
	int freq[26] = {0};
	queue<char> q;
	string res = "";
	for (int i = 0; i < A.size(); i++)
	{
		q.push(A[i]);
		freq[A[i] - 'a']++;
		while (!q.empty() && freq[q.front() - 'a'] > 1)
			q.pop();
		if (q.empty())
			res.push_back('#');
		else
			res.push_back(q.front());
	}
	return res;
}