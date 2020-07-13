#include<bits/stdc++.h>
using namespace std;
void stringLengthHealper(string s,int index,int &countlength)
{
    if(s[index]=='\0')
        return;
    ++countlength;
    stringLengthHealper(s,index+1,countlength);
    return;
}
int stringLength(string s)
{
    int countlength=0;
    stringLengthHealper(s,0,countlength);
    return countlength;
}
int main()
{
    string s="rajnish";
    cout<<stringLength(s)<<endl;
    return 0;
}
