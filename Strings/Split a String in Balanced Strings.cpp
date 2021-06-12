//Loop from left to right maintaining a balance variable when it gets an L increase it by one otherwise decrease it by one.

int balancedStringSplit(string s)
{
    int count = 0, balance = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
            balance++;
        else if (s[i] == 'R')
            balance--;
        if (balance == 0)
            count++;

    }
    return count;
}