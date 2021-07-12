string smallestNumber(int S, int D)
{
        // code here
        if (S == 0)
        {
                if (D == 1)
                        return "1";
                else
                        return "";
        }
        if (S > 9 * D)
                return "";
        S--;
        string res = "";
        for (int i = D - 1; i > 0; i--)
        {
                if (S > 9)
                {
                        res = '9' + res;
                        S -= 9;
                }
                else
                {
                        res = to_string(S) + res;
                        S = 0;
                }
        }
        res = to_string(S + 1) + res;
        return res;
}