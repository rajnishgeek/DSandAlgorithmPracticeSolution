void findMaximumNumHelper(string str, int k, string& maxi, int index)
{
    if (k == 0)
        return;
    int n = str.size();
    char maxChar = str[index];
    //int maxIndex = index;
    for (int i = index + 1; i < n; i++)
    {
        if (maxChar < str[i])
        {
            // maxIndex = i;
            maxChar = str[i];
        }
    }

    if (maxChar != str[index])
        k--;
    for (int i = index; i < n; i++)
    {
        if (str[i] == maxChar)
        {
            swap(str[index], str[i]);
            if (str.compare(maxi) > 0)
                maxi = str;
            findMaximumNumHelper(str, k, maxi, index + 1);
            swap(str[i], str[index]);
        }
    }
}

//Function to find the largest number after k swaps.
string findMaximumNum(string str, int k)
{
    // code here.
    if (str.size() == 1)
        return str;
    string maxi = str;
    findMaximumNumHelper(str, k, maxi, 0);
    return maxi;
}