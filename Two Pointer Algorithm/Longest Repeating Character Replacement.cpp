int characterReplacement(string s, int k)
{
    int n = s.size();
    vector<int> freq(26, 0);
    int windowStart = 0, maxLen = 0, maxCount = 0;
    for (int windowEnd = 0; windowEnd < n; windowEnd++)
    {
        freq[s[windowEnd] - 'A']++;
        maxCount = max(maxCount, freq[s[windowEnd] - 'A']);
        while (windowEnd - windowStart - maxCount + 1 > k)
        {
            freq[s[windowStart] - 'A']--;
            windowStart++;
        }
        maxLen = max(maxLen, windowEnd - windowStart + 1);
    }
    return maxLen;
}