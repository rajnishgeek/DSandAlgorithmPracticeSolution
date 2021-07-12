string reorganizeString(string s)
{
    vector<int> hash(26, 0);
    for (int i = 0; i < s.size(); i++)
        hash[s[i] - 'a']++;

    int max = 0, letter = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < hash[i])
        {
            max = hash[i];
            letter = i;
        }
    }

    if (max > (s.size() + 1) / 2)
        return "";

    string res;
    res.resize(s.size());
    int index = 0;
    while (hash[letter] > 0)
    {
        res[index] = (char)('a' + letter);
        index += 2;
        hash[letter]--;
    }

    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            if (index >= s.size())
            {
                index = 1;
            }

            res[index] = (char)('a' + i);
            index += 2;
            hash[i]--;
        }
    }
    return res;

}

//*******************************************************************
//need improvement
string reorganizeString(string s)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
        freq[s[i] - 'a']++;
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++)
        pq.push({freq[i], (char)('a' + i)});
    string res = "";
    while (!pq.empty())
    {
        pair<int, char> temp1 = pq.top();
        pq.pop();
        if (pq.empty() && temp1.first > 1)
            return "";
        if (pq.empty() && temp1.first == 1)
        {
            res += temp1.second;
            break;
        }
        pair<int, char> temp2 = pq.top();
        pq.pop();
        res += temp1.second + temp2.second;
        temp1.first--;
        temp2.first--;
        if (temp1.first > 0)
            pq.push(temp1);
        if (temp2.first > 0)
            pq.push(temp2);
    }
    return res;
}