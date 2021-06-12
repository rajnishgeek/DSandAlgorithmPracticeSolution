int calculate(string s) {
    stack<long long> myStack;
    char sign = '+';
    long long res = 0;
    long long tmp = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            tmp = 10 * tmp + s[i] - '0';
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
            if (sign == '-')
                myStack.push(-tmp);
            else if (sign == '+')
                myStack.push(tmp);
            else {
                long long num;
                if (sign == '*' )
                    num = myStack.top() * tmp;
                else
                    num = myStack.top() / tmp;
                myStack.pop();
                myStack.push(num);
            }
            sign = s[i];
            tmp = 0;
        }
    }
    while (!myStack.empty()) {
        res += myStack.top();
        myStack.pop();
    }
    return (int)res;
}