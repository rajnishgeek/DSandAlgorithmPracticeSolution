#include<bits/stdc++.h>
using namespace std;
bool isPrime(int &x)
{
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0)
            return false;
    return true;
}

int main()
{
    int t;
    cin>>t;
    bool a[t];
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        a[i]= isPrime(n);
    }
    for(int i=0;i<t;i++)
     a[i]?cout<<"YES"<<endl : cout<<"NO"<<endl;
    return 0;
}

