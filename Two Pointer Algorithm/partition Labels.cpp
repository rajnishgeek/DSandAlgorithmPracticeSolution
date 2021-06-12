vector<int> partitionLabels(string s)
{
    vector<int> res;
    if (s.size() == 0)
        return res;
    vector<int> lastIndex(26);

    //storing last index of each char
    for (int i = 0; i < s.size(); i++)
        lastIndex[s[i] - 'a'] = i;

    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        end = max(end, lastIndex[s[i] - 'a']);
        if (i == end)
        {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}