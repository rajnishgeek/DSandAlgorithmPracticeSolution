bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }

    return true;
}

void partitionHelper(vector<vector<string>> &res, vector<string> &palindromes, string s, int start)
{
    if (palindromes.size() > 0 && start >= s.size())
    {
        res.push_back(palindromes);
        return;
    }
    for (int i = start; i < s.size(); i++)
    {
        if (isPalindrome(s, start, i))
        {
            palindromes.push_back(s.substr(start, i - start + 1));
            partitionHelper(res, palindromes, s, i + 1);
            palindromes.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> palindromes;
    partitionHelper(res, palindromes, s, 0);
    return res;
}