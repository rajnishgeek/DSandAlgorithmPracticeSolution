#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void printReverseString(string s)
{
    if(!s.size())
        return;
     printReverseString(s.substr(1));
     cout<<s[0];
}
int main()
{
    string s;
    cin>>s;
    printReverseString(s);
    return 0;
}
