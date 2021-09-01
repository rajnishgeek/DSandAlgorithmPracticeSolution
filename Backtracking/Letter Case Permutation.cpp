void solve(string s, vector<string> &result, int start)
{
    if (start == s.size())
    {
        result.push_back(s);
        return;
    }

    if (s[start] >= '0' && s[start] <= '9')
    {
        solve(s, result, start + 1);
        return;
    }

    s[start] = tolower(s[start]);
    solve(s, result, start + 1);

    s[start] = toupper(s[start]);
    solve(s, result, start + 1);
}

vector<string> letterCasePermutation(string s)
{
    vector<string> result;
    solve(s, result, 0);
    return result;
}