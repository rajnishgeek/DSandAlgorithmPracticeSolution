int longestSubsequence(int N, int A[])
{
    // code here

    int dp[N];
    for (int i = 0; i < N; i++)
        dp[i] = 1;

    // Start traversing the given array
    for (int i = 1; i < N; i++)
    {
        // Compare with all the previous elements
        for (int j = 0; j < i; j++)
        {
            // If the element is consecutive then
            // consider this subsequence and update
            // dp[i] if required.
            if ((A[i] == A[j] + 1) ||
                    (A[i] == A[j] - 1))

                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    // Longest length will be the maximum value
    // of dp array.
    int result = 1;
    for (int i = 0 ; i < N ; i++)
        if (result < dp[i])
            result = dp[i];
    return result;
}