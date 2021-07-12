bool areIsomorphic(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;
    // Your code here
    int m1[256] = {0}, m2[256] = {0};
    for (int i = 0; i < str1.size(); i++)
    {
        if (m1[str1[i]] != m2[str2[i]])
            return false;
        m1[str1[i]] = i + 1;
        m2[str2[i]] = i + 1;
    }
    return true;
}