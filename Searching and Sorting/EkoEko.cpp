#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maxSawblade(ll a[], ll n, ll m)
{
	if (n == 0 || m < 0)
		return 0;

	ll i, max_element = INT_MIN;
	for (i = 0; i < n; i++)
		if (max_element < a[i])
			max_element = a[i];

	ll start = 0, end = max_element, max_cut = INT_MIN;
	while (start <= end)
	{
		ll sum = 0;
		ll mid = start + (end - start) / 2;
		for (i = 0; i < n; i++)
		{
			if (mid < a[i])
				sum += (a[i] - mid);
		}
		if (sum == m)
			return mid;
		else if (sum > m)
		{
			max_cut = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return max_cut;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	cout << maxSawblade(a, n, m);
	return  0;
}
