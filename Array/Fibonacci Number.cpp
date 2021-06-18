int fib(int n)
{
    int secondPreSum = 0;
    if (n == 0)
        return secondPreSum;
    int firstPreSum = 1;
    if (n == 1)
        return firstPreSum;
    for (int i = 2; i <= n; i++)
    {
        int curr = firstPreSum + secondPreSum;
        secondPreSum = firstPreSum;
        firstPreSum = curr;
    }
    return firstPreSum;
}