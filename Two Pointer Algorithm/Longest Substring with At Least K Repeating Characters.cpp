//RECURSION SOLUTION, TIME O(N), SPACE O(1)
int longestSubstring(string s, int k)
{
    //base casees
    int n = s.size();
    if (n == 0 || n < k)
        return 0;
    if (k <= 1)
        return n;

    //store frequency of each char in map
    unordered_map<char, int> count;
    for (int i = 0; i < n; i++)
        ++count[s[i]];

    int len = 0;
    while (len < n && count[s[len]] >= k)
        len++;
    if (len >= n - 1)
        return len;

    //recursion call
    int x = longestSubstring(s.substr(0, len), k);

    //if still some char left which are less than k
    //so not count that in ans
    while (len < n && count[s[len]] < k)
        len++;

    int y = longestSubstring(s.substr(len), k);
    return max(x, y);
}