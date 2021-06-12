//my approach
vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int> res(temperatures.size());
    stack<int> s;
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            res[i] = 0;
            s.push(i);
        }
        else if (temperatures[i] < temperatures[s.top()])
        {
            res[i] = s.top() - i;
            s.push(i);
        }
        else if (temperatures[i] >= temperatures[s.top()])
        {
            while (!s.empty() && temperatures[i] >= temperatures[s.top()])
                s.pop();
            if (s.empty())
                res[i] = 0;
            else
                res[i] = s.top() - i;
            s.push(i);
        }
    }
    return res;
}