#include<iostream>
using namespace std;

int bubbleSort(int a[], int size)
{
   int countswpes=0;
   for(int i=0;i<size-1;i++)
   {
       for(int j=0;j<size-1-i;j++)
       {
           if(a[j]>a[j+1])
           {
               int temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
               countswpes++;
           }
       }
   }
   return countswpes;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<bubbleSort(a,n)<<endl;
    return 0;
}
