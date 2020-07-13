#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int arraySum(int arr[], int size)
{
	if (size <= 0)
		return 0;
	return (arr[size - 1] + arraySum(arr, size - 1));
}
int main()
{
	int arr[] = {}
	            int n = siezeof(arr) / siezeof(arr[0]);
	cout << arraySum(arr, n) << endl;
	return 0;
}