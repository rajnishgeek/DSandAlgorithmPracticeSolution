#include<bits/stdc++.h>
using namespace std;

int howManyTrueExpression(string s, int i, int j, bool isTrue)
{
	//base case1
	//if string become null
	if (i > j)
		return false;
	//base case2
	//if string has only single element
	if (i == j)
	{
		//this will check for true,if the char is true then it will return trure,else false
		return s[i] == 'T';
	}
	else
	{
		//this will check for false, if the char is false then it will return true
		//because we are checking for false char and we found it, else redturn false
		return s[i] == 'F';
	}


	for (int k = i + 1; k <= j - 1; k = k + 2)
	{
		//now we need to check left and right sub part problem also and make the all combinations
		//for left subpart is true
		int left_true = howManyTrueExpression(s, i, k - 1, true);
		//for left sub part is false
		int left_false = howManyTrueExpression(s, i, k - 1, false);
		//for right right sub part is true
		int right_true = howManyTrueExpression(s, k + 1, j, true);
		//for right sub part is false
		int right_false = howManyTrueExpression(s, k + 1, j, false);

		int ans;
		//check for  & operator
		if (s[k] == '&')
		{
			if (isTrue == true)
			{
				//becouse for end operator
				//T*T=T
				ans += (left_true * right_true);
			}
			else
			{
				//for false combinations
				//T*F=F,F*F=F,F*T=F
				ans += (left_false * right_true + left_false * right_false + left_true * right_false);
			}
		}

		//check for OR operator
		else if (s[k] == '|')
		{
			if (isTrue == true)
			{
				//becouse for OR operator
				//T*F=T,T*T=T,F*T=T
				ans += (left_true * right_true + left_true * right_false + left_false * right_true);
			}
			else
			{
				//for false combinations
				//F*F=F
				ans += (left_false * right_false);
			}
		}

		else if (s[k] == '^')
		{
			if (isTrue == true)
			{
				//becouse for XOR operator
				//T*F=T,F*T=T
				ans += (left_true * right_false + left_false * right_true);
			}
			else
			{
				//check for false combinations
				//F*F=F,T*T=T but it is XOR operator which make 0
				ans += (left_false * right_false + left_true * right_true);
			}
		}
	}

	return ans;
}
int main()
{
	string s = "T^F&T";

	cout << howManyTrueExpression(s, 0, s.size(), 1) << endl;
	return 0;
}