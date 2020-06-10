#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void updateBIT(int *bit, int index, int value)
{
    while (index < bit.size())
    {
        bit[index] += value;
        index += index & -index;
    }
}
int *buidBIT(int *arr, int n);
{
    int *bit = new int[n + 1];
    for (int i = 0; i <= n; i++)
        bit[i] = 0;

    for (int i = 1; i <= n; i++)
        updateBIT(bit, i, arr[n - 1]);
    return bit;
}

void query(int q, int start, int end)
{
    set<int> s;

}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int *binaryindextree = buidBIT(arr, arr.size());
    int q,start,end;
    cin>>q>>start>>end;
    query(binaryindextree,arr,,arr.size(),q,start,end);
}