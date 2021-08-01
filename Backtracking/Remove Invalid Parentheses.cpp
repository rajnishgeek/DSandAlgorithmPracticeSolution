bool isValidString(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            count++;
        else if (s[i] == ')')
            count--;
        if (count < 0)
            return false;
    }
    return count == 0;
}

vector<string> removeInvalidParentheses(string s)
{
    vector<string> res;
    if (s.empty())
        return res;

    set<string> visited;
    queue<string> q;
    q.push(s);
    visited.insert(s);
    bool level = false;

    while (!q.empty())
    {
        s = q.front();
        q.pop();
        if (isValidString(s))
        {
            res.push_back(s);
            level = true;
        }
        if (level)
            continue;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '(' && s[i] == ')')
                continue;

            string temp = s.substr(0, i) + s.substr(i + 1);
            if (!visited.count(temp))
            {
                q.push(temp);
                visited.insert(temp);
            }
        }
    }
    return res;
}



//**************************************************************************
//by DFS
vector<string> res;
int getMin(string s)
{
    stack<char> store;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            store.push(s[i]);
        else if (s[i] == ')')
        {
            if (store.empty())
                store.push(s[i]);
            else if (store.top() == ')')
                store.push(s[i]);
            else if (store.top() == '(')
                store.pop();
        }
    }
    return store.size();
}

void solve(string s, int minRemoval, unordered_set<string> &visited)
{
    if (minRemoval == 0)
    {
        int minRemovalNow = getMin(s);
        if (minRemovalNow == 0)
        {
            if (visited.count(s) == 0)
            {
                res.push_back(s);
                visited.insert(s);
            }
        }
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            solve(left + right, minRemoval - 1, visited);
        }
    }
}

vector<string> removeInvalidParentheses(string s)
{
    res.clear();
    int minRemoval = getMin(s);
    unordered_set<string> visited;
    solve(s, minRemoval, visited);
    return res;
}