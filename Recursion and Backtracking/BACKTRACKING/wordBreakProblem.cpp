#include<bits/stdc++.h>
using namespace std;

//this function has the dictionary and it will comapaire the
//given word with each string of dictionary string with comapar inbuilt function
//compare funtion return 0 if word found.
int compaireDictionary(string &word)
{
	string dictionary[] = {"mobile", "samsung", "sam", "sung",
	                       "man", "mango", "icecream", "and",
	                       "go", "i", "love", "ice", "cream"
	                      };
	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
	{
		//here check the word present in dictionary or not
		//compare inbuilt function compaire the word if found then it return 0
		if (dictionary[i].compare(word) == 0)
			return true;
	}
	return false;
}

//this is wordbreak funtion healper function
void wordBreakUtill(string str, int size, string result)
{
	for (int i = 1; i < =size; i++)
	{
		string prefixstring = str.substr(0, i);

		//cheack the prefix string is present in the dictionary or not
		if (compaireDictionary(prefixstring))
		{
			if (i == size) //if no char left
			{
				result += prefixstring; //add the result string with the prefix string
				cout << result << endl;
				return;
			}

			//recursion call
			wordBreakUtill(str.substr(i, size - i), size - i, result + prefixstring + " ");
		}
	}
}


void wordBreak(string &str)
{
	wordBreakUtill(str, str.size(), "");
}
int main()
{
	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");
	cout << "****************************************************" << endl;
	cout << "\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
	return 0;
}
