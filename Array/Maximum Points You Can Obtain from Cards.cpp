int maxScore(vector<int>& cardPoints, int k)
{
    int n = cardPoints.size();
    int windowSize = n - k;
    int total = 0, curr = 0, minimum = INT_MAX;

    for (int i = 0, j = 0; j < n; j++)
    {
        total += cardPoints[j];
        curr += cardPoints[j];
        if (j - i + 1 == windowSize)
        {
            minimum = min(minimum, curr);
            curr -= cardPoints[i++];
        }
    }
    return (total - (minimum == INT_MAX ? 0 : minimum));
}