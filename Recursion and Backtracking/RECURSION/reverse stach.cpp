#include<bits/stdc++.h>
#include<iostream>
using namespace std;
stack<int> s;
void atBottom(int n)
{
    if(s.size()==0)
        s.push(n);
    int a=s.top();
    s.pop();
    atBottom(n);
    s.push(a);
}
void reverse()
{
    if(!s.size())
        return;
    int a=s.top();
    s.pop();
    reverse();
    atBottom(a);
}
int main()
{
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"original stack"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    reverse();
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
