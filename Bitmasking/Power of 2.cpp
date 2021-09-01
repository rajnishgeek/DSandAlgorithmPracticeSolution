bool isPowerofTwo(long long n)
{

    // Your code here
    int setBit = 0;
    while (n)
    {
        if (n & 1)
            setBit++;
        n >>= 1;
    }
    return setBit == 1;
}