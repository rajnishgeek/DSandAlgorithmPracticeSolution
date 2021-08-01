unordered_map<string, bool> dp;
bool isInterleaveHelper(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int  p2, int p3)
{
    if (p3 == len3)
        return (p1 == len1 && p2 == len2) ? true : false;
    string key = to_string(p1) + '*' + to_string(p2) + '*' + to_string(p3);
    if (dp.count(key))
        return dp[key];
    if (p1 == len1)
        return dp[key] = s2[p2] == s3[p3] ? isInterleaveHelper(s1, s2, s3, len1, len2, len3, p1, p2 + 1, p3 + 1) : false;
    if (p2 == len2)
        return dp[key] = s1[p1] == s3[p3] ? isInterleaveHelper(s1, s2, s3, len1, len2, len3, p1 + 1, p2, p3 + 1) : false;
    bool temp1 = false, temp2 = false;
    if (s1[p1] == s3[p3])
        temp1 = isInterleaveHelper(s1, s2, s3, len1, len2, len3, p1 + 1, p2, p3 + 1);
    if (s2[p2] == s3[p3])
        temp2 = isInterleaveHelper(s1, s2, s3, len1, len2, len3, p1, p2 + 1, p3 + 1);
    return dp[key] = temp1 || temp2;
}

bool isInterleave(string s1, string s2, string s3)
{
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    if (len1 + len2 != len3)
        return false;
    dp.clear();
    return isInterleaveHelper(s1, s2, s3, len1, len2, len3, 0, 0, 0);
}