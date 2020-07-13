#include<bits/stdc++.h>
using namespace std;

void printMaxChocolateHealper(int &totalchoclate, int chocolate, int wrap)
{
	//base case
	if (chocolate < wrap)
		return;
	//add all choclate
	totalchoclate += (chocolate / wrap) ;
	int next = (chocolate / wrap) + (chocolate % wrap);
	printMaxChocolateHealper(totalchoclate, next, wrap);
}
void printMaxChocolate(int money, int price, int wrap)
{
	if (money < price)
	{
		cout << "0" << endl;
		return;
	}
	int totalchoclate = money / price;
	printMaxChocolateHealper(totalchoclate, totalchoclate, wrap);
	cout << totalchoclate << endl;
}
int main()
{
	int money = 15 ; // total money
	int price = 1; // cost of each candy
	int wrap = 3 ; // no of wrappers needs to be

	printMaxChocolate(money, price, wrap);
	return 0;
}