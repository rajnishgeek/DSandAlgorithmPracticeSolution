#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void maxActivitySelected(multimap<int , int> m)
{
	auto it1 = m.begin();
	cout << "start - " << it1->second << "  end - " << it1->first << endl;
	for (auto it2 = it1++; it2 != m.end(); it2++)
	{
		if (it2->first >= it1->first)
		{
			cout << "start - " << it2->second << "  end - " << it2->first << endl;
			it1 = it2;
		}
	}
}
int main()
{
	//here key denote the finish time and value denote the start time
	multimap<int, int> m;
	//int s[] =  {1, 3, 0, 5, 8, 5};
	//int f[] =  {2, 4, 6, 7, 9, 9};
	m.insert(make_pair(9, 8));
	m.insert(make_pair(9, 5));
	m.insert(make_pair(7, 5));
	m.insert(make_pair(6, 0));
	m.insert(make_pair(4, 3));
	m.insert(make_pair(2, 1));
	maxActivitySelected(m);
	return 0;
}