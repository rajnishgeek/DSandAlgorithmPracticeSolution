#include<bits/stdc++.h>
using namespace std;
void printEqualBinarySumsHealper(int n, string left = "", string right = "", int diff = 0)
{
	if (n == 0)
	{
		if (diff == 0)
			cout << left + right << " ";
		return;
	}
	if (n == 1)
	{
		if (diff == 0)
		{
			cout << left + "0" + right << " ";
			cout << left + "1" + right << " ";
		}
		return;
	}
	if ((2 * abs(n)) <= n)
	{
		if (left != "")
		{
			//add 0 at end of left and right string and diff will be same(left-right)
			printEqualBinarySumsHealper(n - 2, left + "0", right + "0", diff);

			//add 1 to right strign and subtract 1 from diff
			//because diff=left.size()-right.size()
			printEqualBinarySumsHealper(n - 2, left + "0", right + "1", diff - 1);
		}
		//at end add 1 to left and 0 to right string
		printEqualBinarySumsHealper(n - 2, left + "1", right + "0", diff + 1);

		//at end add 1-1 left and right string
		printEqualBinarySumsHealper(n - 2, left + "1", right + "1", diff);
	}
	return;
}
int main()
{
	int n = 4;
	printEqualBinarySumsHealper(n);
	return 0;
}
/*//this code is compiled but not running
void printEqualBinarySumsHealper(int n,string s)
{
    if(s.size()==n)
    {
        int l=0,r=0;
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            l+=(s[i]-'0');
            r+=(s[j]-'0');
        }
        if(l==r)
        cout<<s<<" ";
        return;
    }
    if(s[s.size()-1]=='0')
    {
        s.push_back('0');
         printEqualBinarySumsHealper(n,s);
    }
    if(s[s.size()-1]=='0')
    {
        s.push_back('1');
         printEqualBinarySumsHealper(n,s);
    }if(s[s.size()-1]=='1')
    {
        s.push_back('0');
         printEqualBinarySumsHealper(n,s);
    }
    if(s[s.size()-1]=='1')
    {
        s.push_back('1');
         printEqualBinarySumsHealper(n,s);
    }
    return;
}
void printEqualBinarySums(int n)
{
    if(n<=0)
    return;
    if(n==1)
    {
        cout<<1<<" ";
        return;
    }
    printEqualBinarySumsHealper(n, " ");
    return;
}
*/