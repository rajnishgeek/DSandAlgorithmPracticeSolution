/* time complexity of best,worst, average case is O(nlog(n))
   space complexity is O(n)
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void mergeSortedArray(int arr[], int low, int mid, int high)
{
	int left_array_size = mid - low + 1;
	int right_array_size = high - mid;
	int leftarray[left_array_size];
	int rightarray[right_array_size];
	int i, j;

	for (i = 0; i < left_array_size; i++)
		leftarray[i] = arr[low + i];

	for (j = 0; j < right_array_size; j++)
		rightarray[j] = arr[mid + 1 + j];

	int k = 0; //for merged arr index
	i = 0; //for left array index
	j = 0; //for right array index
	while (i < left_array_size && j < right_array_size)
	{
		if (leftarray[i] <= rightarray[j])
		{
			arr[k] = leftarray[i];
			i++;
		}
		else
		{
			arr[k] = rightarray[j];
			j++;
		}
		k++;
	}

	while (i < left_array_size)
	{
		arr[k] = leftarray[i];
		i++;
		k++;
	}

	while (j < right_array_size)
	{
		arr[k] = rightarray[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		mergeSortedArray(arr, low, mid, high);
	}
}
int main()
{
	int arr[] = {56, 3, 6, 7, 2, 1};
	int size = sizeof(arr) / sizeof(int);
	mergeSort(arr, 0, size - 1);
	return 0;
}