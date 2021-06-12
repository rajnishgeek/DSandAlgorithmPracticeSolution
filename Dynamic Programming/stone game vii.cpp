int dp[1000][1000];
int solve(vector<int> &stones, int start, int end, int sum)
{
    //base case, array has one element
    if (start == end)
        return 0;

//array has two element
    if (end - start == 1)
        return max(stones[start], stones[end]);

    if (dp[start][end] != -1)
        return dp[start][end];

    int maxDifference = max(sum - stones[start] - solve(stones, start + 1, end, sum - stones[start]), sum - stones[end] - solve(stones, start, end - 1, sum - stones[end]));

    return dp[start][end] = maxDifference;
}

int stoneGameVII(vector<int>& stones)
{
    memset(dp, -1, sizeof dp);
    int sum = 0;
    for (int i = 0; i < stones.size(); i++)
        sum += stones[i];
    return solve(stones, 0, stones.size() - 1, sum);
}