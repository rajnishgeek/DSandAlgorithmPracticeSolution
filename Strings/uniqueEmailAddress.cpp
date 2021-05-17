int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> m;
        for(int i=0;i<emails.size();i++)
        {
            string s;
            for(int j=0;j<emails[i].size();j++)
            {
                if(emails[i][j]=='+' || emails[i][j]=='@')
                    break;
                if(emails[i][j]=='.')
                    continue;
                s+=emails[i][j];
            }
            s+=emails[i].substr(emails[i].find('@'));
            m.insert(s);
        }
        return m.size();
    }