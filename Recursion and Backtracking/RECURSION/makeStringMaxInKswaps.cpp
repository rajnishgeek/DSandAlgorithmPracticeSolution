#include<bits/stdc++.h>
using namespace std;

void printMaxStringhealper(string &s, int size, int k, string &maxstring)
{
	//base case
	if (size <= 0)
		return;

	//storing max string between current string and previous string
	maxstring = max(maxstring, s);
	printMaxStringhealper(s, size - 1, k, maxstring);
	for (int i = size - 2; i >= 0; --i)
		if (k > 0)
		{
			swap(s[i], s[size - 1]);
			printMaxStringhealper(s, size - 1, k - 1, maxstring);

			//this is backtracking call
			swap(s[i], s[size - 1]);
		}
}
void printMaxString(string s, int  k)
{
	string max = s;
	printMaxStringhealper(s, s.size(), k, max);
	cout << max ;
}

int main()
{
	string s = "1234";
	int k = 2;
	printMaxString(s, k);
	return 0;
}