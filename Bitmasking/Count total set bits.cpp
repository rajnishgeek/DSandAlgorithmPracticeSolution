int largestPowerOf2InRange(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}

int countSetBits(int n)
{
    // Your logic here
    if (n == 0)
        return 0;
    int x = largestPowerOf2InRange(n);
    int bits_till_2_x = x * (1 << (x - 1));
    int msb_2_x_to_n = n - (1 << n) + 1;
    int rest = n - (1 << x);
    int ans = bits_till_2_x + msb_2_x_to_n + countSetBits(rest);
    return ans;
}