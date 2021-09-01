int minDeletions(string s)
{
    int count = 0;
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
        ++freq[s[i] - 'a'];
    unordered_set<int> m;
    for (int i = 0; i < 26;)
    {
        if (freq[i] == 0)
            i++;
        else if (!m.count(freq[i]))
        {
            m.insert(freq[i]);
            i++;
        }
        else if (m.count(freq[i]))
        {
            --freq[i];
            ++count;
        }
    }
    return count;
}