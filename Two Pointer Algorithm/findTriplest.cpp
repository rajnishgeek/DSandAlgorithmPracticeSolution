#include<bits/stdc++.h>
#include<iostream>
using namespace std;


bool twoSum(int arr[], int value, int i, int j)
{
    while (i < j)
    {
        if ((arr[i] + arr[j]) < value)
            i++;
        else if ((arr[i] + arr[j]) > value)
            j--;
        else
            return true;
    }
    return false;
}
bool findTriplets(int arr[], int n)
{
    //Your code here
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
        if (twoSum(arr, -arr[i], i + 1, n - 1))
            return true;
    return false;
}

int main()
{
    int a[] = { -5, -3, 5, 3, 7, 8};
    int n = sizeof(a) / sizeof(int);
    cout << findTriplets(a, n) << endl;
    return 0;
}