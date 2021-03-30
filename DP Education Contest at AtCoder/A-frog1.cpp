#include<bits/stdc++.h>
using namespace std;

int minCost(int a[], int i, int n)
{
    if(i<0)
        return INT_MAX;
    if(i==0)
        return 0;
    int one=0,two=0;
    if(i-1>=0)
        one=abs(a[i]-a[i-1]);
    one+=minCost(a,i-1,n);

    if(i-2>=0)
        two=abs(a[i]-a[i-2]);
    two+=minCost(a,i-2,n);
    return min(one,two);
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<minCost(a,n-1,n)<<endl;
    return 0;

}
