//time O(n)
void extendPalindrome(string s, int start, int end)
{
    while (start >= 0 && end < s.size() && s[start] == s[end])
    {
        count++;
        start--;
        end++;
    }
}

int countSubstrings(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        extendPalindrome(s, i, i);//odd length
        extendPalindrome(s, i, i + 1); //even length
    }
}


//time O(n^2), space O(n^2)
int countSubstrings(string s)
{
    int n = s.size();
    bool dp[n][n];
    int count = 0;
    for (int gape = 0; gape < n; gape++)
    {
        for (int i = 0, j = gape; j < n; i++, j++)
        {
            if (gape == 0)
                dp[i][j] = true;
            else if (gape == 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            if (dp[i][j] == true)
                count++;
        }
    }
    return count;
}