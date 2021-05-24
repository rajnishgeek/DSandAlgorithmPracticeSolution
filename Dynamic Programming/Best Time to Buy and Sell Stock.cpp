//APPROACH 1, time O(N), space O(n)+O(n)
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    if (n <= 1)
        return 0;
    vector<int> mini(n), maxi(n);

    //store minimum left to right till currenet index i
    mini[0] = prices[0];
    for (int i = 1; i < n; i++)
        mini[i] = min(mini[i - 1], prices[i]);

    //store maximum fromt left to right till currenet index i
    maxi[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxi[i] = max(prices[i], maxi[i + 1]);

    int profit = 0;
    for (int i = 0; i < n; i++)
        profit = max(maxi[i] - mini[i], profit);
    return profit;
}

//*******************************************************************************************
//APPROACH 2, TIME O(N), SPACE O(1)
int maxProfit(vector<int>& prices)
{
    int maxProfit = 0, minElement = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        maxProfit = max(maxProfit, prices[i] - minElement);
        minElement = min(minElement, prices[i]);
    }
    return maxProfit;
}