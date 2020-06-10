/*
   this code count the number or swipes required for making the given array sorted 
   time complexity is O(nlog(n))
   space complexity is O(n)
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void update(int bit[], int size, int index, int value)
{
    while (index <= size)
    {
        bit[index] += value;
        index += index & -index;
    }
}
int getSum(int bit[], int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}

void arrangeArray(int arr[], int size)
{
    int temp_array[size];
    for (int i = 0; i < size; i++)
        temp_array[i] = arr[i];

    sort(temp_array, temp_array + size);
    for (int i = 0; i < size; i++)
        arr[i] = lower_bound(temp_array, temp_array + size, arr[i]) - temp_array + 1;
}
int countInversion(int arr[], int size)
{
    int count = 0;
    arrangeArray(arr, size);
    int bit[size + 1];
    for (int i = 0; i < size; i++)
        bit[i] = 0;

    for (int i = size - 1; i > 0; i--)
    {
        count += getSum(bit, arr[i] - 1);
        update(bit, size, arr[i], 1);
    }
    return count;
}
int main()
{
    int arr[] = {-2, 7, 3, -1};
    int size = sizeof(arr) / sizeof(int);
    cout << countInversion(arr, size) << endl;
    return 0;
}