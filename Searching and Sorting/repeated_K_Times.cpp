
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        map<int,int>::iterator it;
        if(m.count(value))
        {
            it=m.find(value);
            it->second= ++(it->second);
        }
        else
         m.insert(make_pair(value,1));
    }
    int k;
    cin>>k;
    for(auto it=m.begin();it!=m.end();it++)
    {
       if(it->second == k)
       {
           cout<<it->first<<endl;
           break;
       }
    }
    return 0;
}
