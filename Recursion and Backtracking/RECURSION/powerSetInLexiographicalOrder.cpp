#include<bits/stdc++.h>
using namespace std;

void stringPermutaion(string s,int size,int index=-1,string curr="")
{
   //base case
   if(index==size)
    return;
   cout<<curr<<" ";
   for(int i=index+1;i<size;i++)
   {
       curr+=s[i];
       stringPermutaion(s,size,i,curr);

       //this is backtracking condition
       curr=curr.erase(curr.size()-1);
   }
   return;
}
void powerSet(string s)
{
   //first sort the string
   sort(s.begin(),s.end());
   stringPermutaion(s,s.size());
}
int main()
{
    string s="abc";
    powerSet(s);
    return 0;
}
