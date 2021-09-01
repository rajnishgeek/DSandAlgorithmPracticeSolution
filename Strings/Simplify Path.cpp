string simplifyPath(string path)
{
    stack<string> st;
    string result;
    boost::split(result, input, boost::is_any_of("/"));
    for (string dir : result)
    {
        if (dir.compare("..") == 0 && !st.empty())
            st.pop();
        else if (!(dir.compare("..") == 0 || dir.compare(".") == 0 || dir.compare("") == 0))
            st.push(dir);
    }
    result = "";
    while (!st.empty())
    {
        result = '/' + st.top() + result;
        st.pop();
    }
    return result.empty() ? "/" : result;
}