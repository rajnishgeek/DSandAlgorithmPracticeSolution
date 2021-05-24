#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int minOperation(ll arr[], ll n, ll a, ll b)
{
	if (n <= 1 || a <= b)
		return 0;
	set<ll> s;
	for (ll i = 0; i < n; i++)
		s.insert(arr[i]);

	ll lastElement = arr[n - 1], secondLastElement = arr[n - 2];
	//a>b
	int count = 0;
	while (lastElement >= 0 || secondLastElement >= 0)
	{
		count++;
		lastElement -= a;
		secondLastElement -= b;
		if (lastElement < secondLastElement)
			swap(lastElement, secondLastElement);
	}
	return count;
}

int main()
{
	ll n, a, b;
	cin >> n;
	ll arr[n];
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	cin >> a >> b;
	cout << minOperation(arr, n, a, b) << endl;
	return 0;
}