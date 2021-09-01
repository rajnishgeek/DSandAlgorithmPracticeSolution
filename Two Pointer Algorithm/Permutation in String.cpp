bool checkInclusion(string s1, string s2)
{
    int len1 = s1.size(), len2 = s2.size();
    if (len1 > len2)
        return false;
    vector<int> hash_s1(26, 0), hash_s2(26, 0);
    int left = 0, right = 0;
    while (right < len1)
    {
        hash_s1[s1[right] - 'a']++;
        hash_s2[s2[right] - 'a']++;
        right++;
    }
    right--;
    while (right < len2)
    {
        if (hash_s1 == hash_s2)
            return true;
        right++;
        if (right >= len2)
            break;
        hash_s2[s2[right] - 'a']++;
        hash_s2[s2[left] - 'a']--;
        left++;
    }
    return false;
}