#include<bits/stdc++.h>
using namespace std;

void combinationFactorHelaper(int firstproduct, int product, int n, vector<vector<int>> &allfactors, vector<int> factors)
{
	//base case 1
	//if product or first product become greater than our n value
	if (firstproduct > n || product > n)
		return;

	//base case 2
	//oue peduct is equal to n then push the factor vector into the resultan vector
	if (product == n)
	{
		allfactors.push_back(factors);
		return;
	}
	for (int i = firstproduct; i < n; i++)
	{
		if (i * product > n)
			break;
		if (n % i == 0)
		{
			factors.push_back(i);
			combinationFactorHelaper(i, i * product, n, allfactors, factors);
			factors.pop_back();
		}
	}
}
void combinationFactor(int n)
{
	vector<vector<int>> allfactors;
	vector<int> factors;
	allfactors.clear();
	factors.clear();
	combinationFactorHelaper(2, 1, n, allfactors, factors);
	for (int i = 0; i < allfactors.size(); i++)
	{
		for (int j = 0; j < allfactors[i].size(); j++)
			cout << allfactors[i][i] << " ";
		cout << endl;
	}
}
int main()
{
	int n = 16;
	combinationFactor(n);
	return 0;
}

