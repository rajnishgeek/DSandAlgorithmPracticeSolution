#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//properties that a single job has
struct Job
{
	char id;
	int deadline;
	int profit;
};

//this function just comapaire and tell first value should placed before second value or not
bool compairProfits(Job a, Job b)
{
	return (a.profit > b.profit);
}

//it will print the maximum profit job sequence
void printJobScheduling(Job arr[], int n)
{
	sort(arr, arr + n, compairProfits);
	int result[n];
	bool slots[n];
	//marks all slots false that is available
	for (int i = 0; i < n; i++)
		slots[i] = false;
	for (int i = 0; i < n; i++)
	{
		//thsi j value is because we want to get maximum value of slot
		for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
		{
			if (!slots[j]) //this is false means slots is available
			{
				result[j] = i;
				slots[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (slots[i])
			cout << arr[result[i]].id << " ";
}

int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
		{'d', 1, 25}, {'e', 3, 15}
	};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs " << endl;
	printJobScheduling(arr, n);
	return 0;
}
