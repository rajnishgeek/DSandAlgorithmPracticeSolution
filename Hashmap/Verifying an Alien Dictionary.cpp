bool isInOrder(string &a, string &b, unordered_map<char, int> &m)
{
    for (int i = 0; i < a.size() && i < b.size(); i++)
    {
        if (m[a[i]] != m[b[i]])
            return (m[a[i]] < m[b[i]]);
    }
    return (a.size() <= b.size());
}

bool isAlienSorted(vector<string>& words, string order)
{
    unordered_map<char, int> m;
    for (int i = 0; i < order.size(); i++)
        m[order[i]] = i;
    for (int i = 0; i < words.size() - 1; i++)
    {
        if (isInOrder(words[i], words[i + 1], m) == false)
            return false;
    }
    return true;
}