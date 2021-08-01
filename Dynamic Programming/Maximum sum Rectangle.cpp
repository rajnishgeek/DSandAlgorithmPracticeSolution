int kadaneAlgo(vector<int> a, int n)
{
        int maxi = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
                sum += a[i];
                if (maxi < sum)
                        maxi = sum;
                if (sum < 0)
                        sum = 0;
        }
        return maxi;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
        // code here
        int maxSum = INT_MIN;
        for (int times = 0; times < R; times++)
        {
                vector<int> sums(C, 0);
                for (int i = times; i < R; i++)
                {
                        for (int j = 0; j < C; j++)
                                sums[j] += M[i][j];
                        maxSum = max(maxSum, kadaneAlgo(sums, C));
                }
        }
        return maxSum;
}