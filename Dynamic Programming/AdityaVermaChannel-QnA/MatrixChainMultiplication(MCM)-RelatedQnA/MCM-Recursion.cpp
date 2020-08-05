#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int arr[], int i, int j)
{
	//base case
	//initial index become grater than end index
	// or if equal then array must contain more than one element
	if (i >= j)
		return 0;

	int min_cost = INT_MAX;

	//k run till j-1 because k and j will become equal than return
	//right array should also must have one element for function calling
	for (int k = i; k <= j - 1; k++)
	{
		int temp_min = matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j-1]);

		//comapair if less then update mincost value
		if (temp_min < min_cost)
			min_cost = temp_min;
	}
	//final mincost will be store in mincost variable so return it
	return min_cost;
}
int main()
{
	int arr[] = {40, 20, 30, 10, 30};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << matrixChainMultiplication(arr, 1, n) << endl;
	return 0;
}
