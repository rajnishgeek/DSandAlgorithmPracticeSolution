#include<bits/stdc++.h>
using namespace std;

stack<int> s;
void insertAtBottom(int x)
{
	if (s.size() == 0)
		s.push(x);
	else
	{
		int a = s.top();
		s.pop();
		insertAtBottom(x);
		s.push(a);
	}

}
void reverseStack()
{
	if (s.size() > 0)
	{
		int x = s.top();
		s.pop();
		reverseStack();
		insertAtBottom(x);
	}
}

int main()
{
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	reverseStack();
	string str;
	while (!s.empty())
	{
		str.push_back(s.top());
		s.pop();
	}

	cout << str[3] << " " << str[2] << " " << str[1] << " " << str[0] << endl;
	return 0;
}