#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void update(int bit[], long long int size, long long int index, long long int value)
{
    while (index <= size)
    {
        bit[index] += value;
        index += index & -index;
    }
}
long long int getSum(int bit[], long long int index)
{
    long long int sum = 0;
    while (index > 0)
    {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}
void arrangeArray(int arr[], long long int size)
{
    int temp_array[size];
    for (long long int i = 0; i < size; i++)
        temp_array[i] = arr[i];

    sort(temp_array, temp_array + size);
    for (long long int i = 0; i < size; i++)
        arr[i] = lower_bound(temp_array, temp_array + size, arr[i]) - temp_array + 1;
}
void constructBIT(int arr[], int bit[], long long int n)
{
    for (long long int i = 0; i < n; i++)
        bit[i] = 0;

    for (long long int i = 0; i < n; i++)
        if (bit[(i + 1)] == 0)
            update(bit, n, arr[i], 1);
}
int main()
{
    long long int n;
    int arr[n];
    for (long long int i = 0; i < n; i++)
        cin >> arr[i];
    long long int q;
    cin >> q;
    arrangeArray(arr, n);
    int bit[n];
    constructBIT(arr, bit, n);

    while (q--)
    {
        long long int i, j;
        cin >> i >> j;
        cout << getSum(bit, j) - getSum(bit, i - 1) << endl;
    }
    return 0;
}
