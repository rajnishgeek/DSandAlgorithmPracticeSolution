#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void  printStringCombinationDigits(char *input,int index,char *output,int outputindex)
{
   //base case
   //if string is over means at current index null value present
    if(input[index]=='\0')
    {
        output[outputindex]='\0';
        cout<<output<<endl;
        return;
    }
    output[outputindex]=input[index];

    //place space at next index of output char array
    output[outputindex+1]=' ';

    //call recursive function for input next index and pass output index
    //by +2 because we placed null at next index
    printStringCombinationDigits(input,index+1,output,outputindex+2);
    if(input[index+1]!='\0')
    printStringCombinationDigits(input,index+1,output,outputindex+1);
}
int main()
{
    char input[]="1234";
    char *output=new char[100];
    output[0]='\0';
    printStringCombinationDigits(input,0,output,0);
    return 0;
}
