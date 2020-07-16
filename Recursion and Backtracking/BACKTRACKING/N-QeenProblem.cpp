#include<bits/stdc++.h>
#include<iostream>
using namespace std;


bool placed(int position[],int n,int row, int col)
{
	for (int i = 0; i < row; i++)
		if ((position[i] == col) || (abs(position[i] - col) == abs(i - row)))
			return false;
			       return true;
}
void NQeenHealper(int position[],int n,int row)
{
	for (int i = 0; i < n; i++)
	{
		if (placed(position,n,row, i))
		{
			position[row] = i;
			if (row == n)
			{
				for (int p = 0; p < n; p++)
					cout << position[p] << " ";
				cout << endl;
			}
			else
				NQeenHealper(position,n,row + 1);
		}
	}
}
void NQeen(int position[],int n)
{
	for (int row = 0; row < n; row++)
		NQeenHealper(position,n,row);
}
int main()
{
    int n = 4;
    int position[n];
	NQeen(position,n);
	return 0;
}
