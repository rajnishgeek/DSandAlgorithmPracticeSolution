#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    //int t;
   // cin>>t;
    //while(t)
    //{
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='L')
              x=x-1;
            else if(arr[i]=='R')
                x+=1;
            else if(arr[i]=='U')
                y+=1;
            else if(arr[i]=='D')
                y-=1;
        }
            cout<<x<<"  "<<y<<endl;
   // }
   // t--;
    return 0;
}
