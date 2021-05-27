int evalRPN(vector<string>& tokens)
{
    stack<int> s;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
            if (s.size() == 0)
                s.push(0);
            else
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left + right);
            }
        }
        else if (tokens[i] == "-")
        {
            if (s.size() == 0)
                s.push(0);
            else
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left - right);
            }
        }
        else if (tokens[i] == "*")
        {
            if (s.size() == 0)
                s.push(0);
            else
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left * right);
            }
        }
        else if (tokens[i] == "/")
        {
            if (s.size() == 0)
                s.push(0);
            else
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left / right);
            }
        }
        else
            s.push(stoi(tokens[i]));
    }
    return s.top();
}