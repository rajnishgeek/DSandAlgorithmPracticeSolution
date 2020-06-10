#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//this function is for making segment tree of sum of left and right child
void builSegmentTree(string &a, int *segmenttree, int s, int e, int index)
{
    if (s == e)
    {
        segmenttree[index] = a[s] - '0';
        return;
    }

    int mid = (s + e) / 2;
    builSegmentTree(a, segmenttree, s, mid, 2 * index);
    builSegmentTree(a, segmenttree, mid + 1, e, 2 * index + 1);
    segmenttree[index] = segmenttree[2 * index] + segmenttree[2 * index + 1];
    return;
}

//this function is for upadation
void updateSegmentTree(int *segmenttree, int index, int s, int e, int position, int value)
{
    if (position < s || position > e)
        return;

    if (s == e)
    {
        segmenttree[index] = value;
        return;
    }

    int mid = (s + e) / 2;
    updateSegmentTree(segmenttree, 2 * index, s, mid, position, value);
    updateSegmentTree(segmenttree, 2 * index + 1, mid + 1, e, position, value);
    segmenttree[index] = segmenttree[2 * index] + segmenttree[2 * index + 1];
    return;
}

//this function will count divisible of 3
void countDivisibleBy3(int *segmenttree, int index, int s, int e, int qs, int qe, int &count)
{
    if (qe < s || qs > e)
        return;
    if (qs <= s && qe >= e)
    {
        if (segmenttree[index] % 3 == 0)
            count++;
        return;
    }

    int mid = (s + e) / 2;
    countDivisibleBy3(segmenttree, 2 * index, s, mid, qs, qe, count);
    countDivisibleBy3(segmenttree, 2 * index + 1, mid + 1, e, qs, qe, count);
    if ((segmenttree[2 * index] + segmenttree[2 * index + 1]) % 3 == 0)
        count++;
    return;
}
int main()
{
    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    int *segmenttree = new int[4 * n + 1];
    builSegmentTree(a, segmenttree, 0, n - 1, 1);
    while (q--)
    {
        int x, i, j;
        cin >> x >> i >> j;

        //for query 1 here i is index and j is value that we want to put
        if (x == 1)
            updateSegmentTree(segmenttree, 1, 0, n - 1, i - 1, j);
        //for query 2 i is starting and j is ending range value
        else if (x == 2)
        {
            int count = 0;
            countDivisibleBy3(segmenttree, 1, 0, n - 1, i - 1, j - 1, count);
            i--;
            while (i < j)
            {
                if (a[i] % 3 == 0)
                    count++;
            }
            cout << count << endl;
        }
    }
}
