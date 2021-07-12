long long maxProduct(int *arr, int n)
{
    if (n == 1)
        return arr[0];
    int max_neg = INT_MAX;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_zero++;
            continue;
        }

        if (arr[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg, arr[i]);
        }
        prod *= arr[i];
    }
    if (count_zero == n)
        return 0;
    if (count_neg & 1)
    {
        if (count_neg == 1 && count_neg + count_zero == n && count_zero > 0)
            return 0;
        prod /= max_neg;
    }
    return prod;
}