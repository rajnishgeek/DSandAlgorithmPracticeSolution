#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countVowels(string s, int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(s[i]=='A')
         count++;
        else if(s[i]=='E')
         count++;
        else if(s[i]=='I')
         count++;
        else if(s[i]=='O')
         count++;
        else if(s[i]=='U')
         count++;

        else if(s[i]=='a')
         count++;
        else if(s[i]=='e')
         count++;
        else if(s[i]=='i')
         count++;
        else if(s[i]=='o')
         count++;
        else if(s[i]=='u')
         count++;
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int size=s.size();
        cout<<countVowels(s,size)<<endl;
    }
    return 0;
}
