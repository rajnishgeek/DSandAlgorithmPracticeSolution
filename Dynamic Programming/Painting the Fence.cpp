long long countWays(int n, int k)
{
        // code here
        long long same = 0;
        long long diff = k;
        long long total = k;
        int mod = pow(10, 9) + 7;

        for (int i = 2; i <= n; i++)
        {
                same = diff ;
                diff = total * (k - 1);
                diff = diff % mod;
                total = (same + diff) % mod;
        }
        return total;
}