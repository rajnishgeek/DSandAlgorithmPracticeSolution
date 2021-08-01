/*
using backtracking
using backtracking we can find all the possible sentances
but using DP we can only find the number of possible sentances
*/
vector<string> res;
bool isDictionaryContains(vector<string> &dict, string &word)
{
    for (int i = 0; i < dict.size(); i++)
    {
        if (dict[i].compare(word) == 0)
            return true;
    }
    return false;
}

void wordBreakUtill(string s, int n, string resultString, vector<string> &dict)
{
    for (int i = 1; i <= n; i++)
    {
        string prefix = s.substr(0, i);
        if (isDictionaryContains(dict, prefix))
        {
            if (i == n)
            {
                resultString += prefix;
                res.push_back(resultString);
                return;
            }
            wordBreakUtill(s.substr(i, n - i), n - i, resultString + prefix + " ", dict);
        }

    }
}

vector<string> wordBreak(int n, vector<string>& dict, string s)
{
    // code here
    res.clear();
    wordBreakUtill(s, s.size(), "", dict);
    return res;
}