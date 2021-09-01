vector<string> AllPossibleStrings(string s)
{
    // Code here
    vector<string> result;
    int n = s.size();
    //int power=pow(2,n);

    unsigned int pow_set_size = pow(2, n);
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for (counter = 0; counter < pow_set_size; counter++)
    {
        string v = "";
        for (j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from set */
            if (counter & (1 << j))
            {
                v.push_back(s[j]);
                // result.push_back(v);
            }

        }
        if (v.empty() == false)
            result.push_back(v);
    }
    sort(result.begin(), result.end());
    return result;
}