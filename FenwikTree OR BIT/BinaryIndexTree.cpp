#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//for upadation of BIT
void updateBIT(int *bit, int index, int value)
{
    while (index < bit.size())
    {
        bit[index] += value;
        index += index & -index;
    }
}
//function for constructing binary index tree or fenwick tree
int *constructBIT(int *arr, int n)
{
    int *bit = new int[n + 1];
    for (int i = 0; i <= n; i++) //make arr index value 0
        bit[i] = 0;

    //contruction of binary index tree is same as updation of bit
    for (int i = 1; i <= n; i++)
        updateBIT(bit, i, arr[i - 1]);
    return bit;
}

//function for finding sum
int sum(int *bit, int index)
{
    int sumvalue = 0;
    index++;
    while (index > 0)
    {
        sumvalue += bit[index];
        index -= index & -index;
    }
    return sumvalue;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *binaryindextree = constructBIT(arr, arr.size());
}