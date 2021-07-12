vector<int> candyStore(int candies[], int N, int K)
{
    // Write Your Code here
    sort(candies, candies + N);
    int min = 0, max = 0;
    for (int i = 0, j = N - 1; i < N && i <= j; i++)
    {
        min += candies[i];
        j -= K;
    }
    for (int i = N - 1, j = 0; i >= 0 && j <= i; i--)
    {
        max += candies[i];
        j += K;
    }
    vector<int> res = {min, max};
    return res;
}