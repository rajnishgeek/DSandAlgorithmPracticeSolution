//time O(n)*length of p
vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    int window = p.size();
    int len = s.size();
    if (len < window)
        return res;

    int left = 0, right = 0;
    vector<int> p_hash(26, 0), s_hash(26, 0);
    while (right < window)
    {
        p_hash[p[right] - 'a']++;
        s_hash[s[right] - 'a']++;
        right++;
    }
    right--;
    while (right < len)
    {
        if (p_hash == s_hash)
            res.push_back(left);
        right++;
        if (right != len)
            s_hash[s[right] - 'a']++;
        s_hash[s[left] - 'a']--;
        left++;
    }
    return res;
}


//time O(n^2)
vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    unordered_map<char, int> m;
    for (int i = 0; i < p.size(); i++)
        ++m[p[i]];
    for (int i = 0, j = p.size() - 1; j < s.size(); i++, j++)
    {
        auto temp = m;
        bool flag = true;
        for (int k = i; k <= j; k++)
        {
            if (temp[s[k]] > 0)
                temp[s[k]]--;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            res.push_back(i);
    }
    return res;
}