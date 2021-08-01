int ways(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return false;
    if (i == j)
    {
        if (s[i] == 'T')
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    int ans = 0;
    for (int k = i; k <= j - 1; k += 2)
    {
        int leftTrue = ways(s, i, k - 1, true);
        int leftFalse = ways(s, i, k - 1, false);
        int rightTrue = ways(s, k + 1, j, true);
        int rightFalse = ways(s, k + 1, j, false);


        if (s[k] == '&')
        {
            if (isTrue == true)
                ans = ans + leftTrue * rightTrue;
            else
                ans = ans + leftFalse * rightTrue + leftFalse * rightFalse + leftTrue * rightFalse;
        }
        else if (s[k] == '|')
        {
            if (isTrue = true)
                ans = ans + leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
            else
                ans = ans + leftFalse + rightFalse;
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans = ans + leftFalse * rightTrue + leftTrue * rightFalse;
            else
                ans = ans + leftTrue * rightTrue + leftFalse * rightFalse;
        }
    }
    return ans;
}
public:
int countWays(int N, string S)
{
    // code here
    return ways(S, 0, S.size() - 1, true);
}