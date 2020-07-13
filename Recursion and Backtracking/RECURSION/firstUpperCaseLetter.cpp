#include<bits/stdc++.h>
using namespace std;
int firstUpperCaseLetterHealper(string s,int index)
{
    if(s[index]=='\0')
        return -1;
    if(s[index]>='A' && s[index]<='Z')
        return index;
    return firstUpperCaseLetterHealper(s,index+1);
}
void firstUpperCaseLetter(string s)
{
    if(firstUpperCaseLetterHealper(s,0)==-1)
        cout<<"Not contain any upper case latter"<<endl;
    else
     cout<<s[firstUpperCaseLetterHealper(s,0)]<<endl;
}
int main()
{
    string s="rajnisH";
    firstUpperCaseLetter(s);
    return 0;
}
