vector<long long> printFirstNegativeInteger(long long int A[],
        long long int N, long long int K)
{
    deque<long long int> q;
    long long int i;
    for (i = 0; i < K; i++)
        if (A[i] < 0)
            q.push_back(i);
    vector<long long> res;

    for (; i < N; i++)
    {
        if (!q.empty())
            res.push_back(A[q.front()]);
        else
            res.push_back(0);
        while (!q.empty() && q.front() < (i - K + 1))
            q.pop_front();
        if (A[i] < 0)
            q.push_back(i);
    }
    if (!q.empty())
        res.push_back(A[q.front()]);
    else
        res.push_back(0);
    return res;
}