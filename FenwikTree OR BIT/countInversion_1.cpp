/*this count inversion function has time complexity = O(nLog(n))
                                    space complexity= O(n)
  this count inversion not work for negative value of array 
  because we are taking given array value as a index in binary index tree*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void update(int *bit, int size, int index, int value)
{
    while (index <= size)
    {
        bit[index] += value;
        index += index & -index;
    }
}

//it will retuen sum prefix sum value
int sum(int bit[], int index)
{
    int sumvalue = 0;
    while (index > 0)
    {
        sumvalue += bit[index];
        index -= index & -index;
    }
    return sumvalue;
}

//this function is for counting number of conversion required for sort the array
int countInversion(int arr[], int n)
{
    int count = 0;
    int maxelement = INT_MIN;
    for (int i = 0; i < n; i++) //finding max. element for bit arr size+1
    {
        if (maxelement < arr[i])
            maxelement = arr[i];
    }

    int bit[maxelement + 1] = {0};

    for (int i = n - 1; i >= 0; i--)
    {
        count += sum(bit, arr[i] - 1);
        update(bit, maxelement, arr[i], 1);
    }
    return count;
}
int main()
{
    int arr[] = {7, 6, 2, 3, 1, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    cout << "count inverstion :- " << countInversion(arr, size) << endl;
    return 0;
}