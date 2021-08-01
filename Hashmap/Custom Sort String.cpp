string customSortString(string order, string str)
{
    char freq[26] = {0};
    for (int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;

    str = "";
    for (int i = 0; i < order.size(); i++)
    {
        int count = freq[order[i] - 'a'];
        if (count > 0)
        {
            while (count--)
                str.push_back(order[i]);
        }
        freq[order[i] - 'a'] = 0;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            while (freq[i]--)
                str.push_back((char)('a' + i));
        }
    }
    return str;
}