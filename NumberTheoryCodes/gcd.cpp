#include<bits/stdc++.h>
using namespace std;
int gcd(int &x, int &y)
{
    int r;
    if(x>y);
    else
    {
        r=x;
        x=y;
        y=r;
    }
    int gcdvalue=0;
    r=x%y;
    if(r==0)
        return x/y;
    while(r)
    {
         gcdvalue=r;
         x=y;
         y=r;
         r=x%y;
    }
    return gcdvalue;
}
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<gcd(x,y)<<endl;
    return 0;
}
