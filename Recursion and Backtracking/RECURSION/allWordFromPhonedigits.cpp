#include<bits/stdc++.h>
using namespace std;
//this is like hash table for finding the crosoponding char for digits
const char table[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printAllWordsHealper(int number[], int n, char output[], int currdigit)
{
	//base case
	if (currdigit == n)
	{
		cout << output << " ";
		return;
	}
	for (int i = 0; i < strlen(table[number[currdigit]]); i++)
	{
	    //store the digit char in output char array
		output[currdigit] = table[number[currdigit]][i];

		//recursion call
		printAllWordsHealper(number, n, output, currdigit + 1);

		//this is because digit 0 and 1 does not have any char
		if (number[currdigit] == 0 || number[currdigit] == 1)
			return;
	}
}
void printAllWords(int number[], int n)
{
	char output[n + 1];
	output[n] = '\0';
	printAllWordsHealper(number, n, output, 0);
	cout<<endl;
}
int main()
{
	int number[] = {2, 3, 4};
	int n = sizeof(number) / sizeof(number[0]);
	printAllWords(number, n);
	return 0;
}
