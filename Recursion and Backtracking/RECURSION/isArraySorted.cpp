#include<bits/stdc++.h>
using namespace std;
//is array sorted using recursion
bool isSortedHealper(int a[], int index)
{
	if (index - 1 < 0)
		return true;
	else if (a[index] < a[index - 1])
		return false;
	return isSortedHealper(a, --index);
}
void isSorted(int a[], int size)
{
	if (size == 0 || size == 1 || isSortedHealper(a, size - 1))
	{
		cout << "YES";
		return;
	}
	else
		cout << "NO";
}
int main()
{
	int a[] = { 20, 23, 23, 45, 78, 88 };
	int size = sizeof(a) / sizeof(a[0]);
	isSorted(a, size);
	return 0;
}