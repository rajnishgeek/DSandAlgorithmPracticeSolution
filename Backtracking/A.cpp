#include<bits/stdc++.h>
using namespace std;

int minLen;

void solve(int n, int sum, vector<int> v)
{
	if (sum > n)
		return;
	if (sum == n)
	{
		unordered_map<int, int> m;
		for (int i = 0; i < v.size(); i++)
			m[v[i]]++;
		bool flag = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] = 1 || (m[v[i]] - 1) > 1 || (m[v[i]] - 2) > 1)
				continue;
			else
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			if (v.size() < minLen)
				minLen = v.size();
		}
	}
	v.push_back(sum + 1)
	solve(n, sum + 1, v);
	v.pop_back();
	v.push_back(sum + 2);
	solve(n, sum + 2, v);
	v.pop_back();
}

int minLenght(int n)
{
	solve(int n, int 1, vector<int> {1});
	return minLen;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		minLen = INT_MAX;
		cout << minLenght(n) << endl;
	}
	return 0;
}