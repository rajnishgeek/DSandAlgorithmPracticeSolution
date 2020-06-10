#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int preFixSum(int bit[], int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}
void update(int bit[], int size, int index, int value)
{
    while (index <= size)
    {
        bit[index] += value;
        index += index & -index;
    }
}

void isPreFixSumExist(int bit[], int size, int sumvlaue)
{
    long long int low = 1, high = size;
    bool flag = 1;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        long long int sum = preFixSum(bit, mid);
        if (sum == sumvlaue)
        {
            cout << "Found"
                 << " " << mid << endl;
            flag = 0;
            break;
        }
        else if (sumvlaue > sum)
            low = mid + 1;

        else if (sumvlaue < sum)
            high = mid - 1;
    }
    if (flag)
        cout << "Not Found" << endl;
}

int *constructBIT(int arr[], int size)
{
    int bit[size + 1];
    for (int i = 0; i <= size; i++)
        bit[i] = 0;

    for (int i = 1; i <= size; i++)
        update(bit, size, i, arr[i - 1]);
    return bit;
}
int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int *bit = constructBIT(arr, n);
    for (int i = 0; i < q; i++)
    {
        int q_no;
        cin >> q_no;
        if (q_no == 1)
        {
            int p, q;
            cin >> p >> q;
            update(bit, n, arr[p - 1], q);
        }
        else if (q_no == 2)
        {
            int S;
            cin >> S;
            isPreFixSumExist(bit, n, S);
        }
    }
    return 0;
}