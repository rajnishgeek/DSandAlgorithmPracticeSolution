#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solver(ll arr[], int start, int end, vector<ll> &v)
{
	ll sum;
	int n = end - start + 1;
	for (int i = 0; i < (1 << n); i++)
	{
		sum = 0;
		int j = start;
		int x = i;
		while (x)
		{
			int l = x & 1;
			if (l)
				sum += arr[j];
			j++;
			x = x >> 1;
		}
		v.push_back(sum);
	}
}

ll subSetSums(ll arr[], int n, ll a, ll b)
{
	if (n == 0)
		return 1;

	vector<ll> v1, v2;
	solver(arr, 0, (n / 2)-1, v1);
	solver(arr, (n / 2), n - 1, v2);

	int count = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		int low = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
		count += (high - low);
	}
	return count;
}

int main()
{
	int n;
	ll a, b;
	cin >> n >> a >> b;
	ll arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << subSetSums(arr, n, a, b);
	return 0;
}
