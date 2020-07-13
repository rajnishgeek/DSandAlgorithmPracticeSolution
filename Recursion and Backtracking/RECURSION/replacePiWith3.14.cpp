#include<bits/stdc++.h>
using namespace std;
string output;
void replacePiHealper(string s, int index)
{
	if (index + 1 >= s.size())
		return;
	else if (s[index] == 'p' && s[index + 1] == 'i')
		output = output + "3.14";
	else
		output = output + s[index];
	replacePiHealper(s, ++i);
}
void replacePi(strign s)
{
	if (s.size() == 0 || s.size() == 1)
		return;
	replacePiHealper(s, i);
}
int main()
{
	string s = "2 * pi + 3 * pi = 5 * pi";
	replacePi(s);
	return 0;
}