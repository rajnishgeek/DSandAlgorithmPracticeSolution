#include<bits/stdc++.h>
using namespace std;
void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int* reverseArrayHealper(int a[], int i, int j)
{
	if (i >= j)
		return a;
	swap(a[i], a[j]);
	reverseArrayHealper(a, ++i, --j);
	return a;
}
void reverseArray(a, n)
{
	if (n == 0 || n == 1)
		return;
	reverseArrayHealper(a, 0, n - 1);
}
int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(a) / sizeof(a[0]);
	reverseArray(a, n);
	printArray(a, n);
	return 0;
}