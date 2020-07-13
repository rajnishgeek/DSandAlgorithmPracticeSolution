#include<bits/stdc++.h>
using namespace std;

void printCombinationsHealper(int input[],int startindex,int endindex,int data[],int index,int r)
{
    //base case
    if(index==r)
    {
        for(int i=0;i<r;i++)
            cout<<data[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=startindex;i<=endindex && endindex-i+1>=r-index;i++)
    {
        data[index]=input[i];
        //recursion call
        printCombinationsHealper(input,startindex+1,endindex,data,index+1,r);

        //this line remove the duplicates if array has duplicate elements
        while(input[i]==input[i+1])
            ++i;
    }
    return;
}
void printCombinations(int input[],int size,int r)
{
    int data[r];
    sort(input,input+size);
    printCombinationsHealper(input,0,size-1,data,0,r);
}
int main()
{
    int input[]={1,2,3,4,5};
    int n=sizeof(input)/sizeof(input[0]),r=3;
    printCombinations(input,n,r);
    return 0;
}
