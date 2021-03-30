#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	set<pair<int , int >> s;
	s.insert(make_pair(10, 1));
	s.insert(make_pair(10, 5));
	s.insert(make_pair(20, 1));
	s.insert(make_pair(10, 100));
	s.insert(make_pair(5, 1));
	s.insert(make_pair(5, 3));

	s.erase(s.find(make_pair(5, 2)));
	s.insert(make_pair(5, 4));

	auto it = s.lower_bound(make_pair(20, 1));
	cout << it->first << "and">>it->second << endl;

	auto it = s.upper_bound(make_pair(20, 1));
	cout << it->first << "and">>it->second << endl;

	for (auto p : s)
	{
		cout << p.first << "and" << p.second << endl;
	}

	return 0;
}