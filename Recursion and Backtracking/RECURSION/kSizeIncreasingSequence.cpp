#include<bits/stdc++.h>
using namespace std;

void printIncreasingSequenceHealper(int data[], int n, int k, int length)
{
    //base case
    if(length==k)
    {
        for(int i=0;i<k;i++)
            cout<<data[i]<<" ";
        cout<<endl;
        return;
    }

    //if at index 0 no element is present then put 1 otherwise increament one in previous value
    int i=(length==0)?1:data[length-1]+1;
    length++;
    for(;i<=n;i++)
    {
        data[length-1]=i;
        printIncreasingSequenceHealper(data,n,k,length);
    }

    //this is importent reduce the length for next call
    length--;
}
void printIncreasingSequence(int n, int k)
{
    int data[k];
    printIncreasingSequenceHealper(data,n,k,0);

}
int main()
{
    int k=3,n=7;
    printIncreasingSequence(n,k);
    return 0;
}
