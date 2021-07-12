bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        int n=pushed.size();
        if(n==0)
            return true;
        stack<int> st;
        for(int i=0,j=0;i<n || j<n;)
        {
            if(st.empty())
             st.push(pushed[i++]);
            else if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else if(st.top()!=popped[j])
            {
                if(i>=n)
                    return false;
                else
                 st.push(pushed[i++]);
            }
        }
        return st.empty();
    }