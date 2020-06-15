/* int this we are using middle element as a pivote element
   time complexity = O(nlog(n));
   space complexit = O(1);
   quick sort is inplace sorining algorithm
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int partin(int arr[], int start, int end)
{
	int pivot_element = arr[start];

	//count no. of smaller element as compare to starting index element
	int count_min_element = 0;
	for (int i = start + 1; i <= end; i++)
		if (arr[i] <= pivot_element)
			count_min_element++;

	//swap starting at pivot idnex
	int pivot_index = start + count_min_element;
	arr[start] = arr[pivot_index];
	arr[pivot_index] = pivot_element;

	int i = start, j = end;
	while (i < pivot_index && j > pivot_index)
	{
		if (arr[i] <= pivot_element)
			i++;
		else if (arr[j] > pivot_element)
			j--
			else
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
	}
	return pivot_index;
}

void quicSort(int arr, int start, int end)
{
	if (start >= end)
		return;
	int partionindex = partin(arr, start, end);
	quicSort(arr, start, partionindex - 1);
	quicSort(arr, partionindex + 1, end);
}
int main()
{
	int arr[] = {5, 1, 7, 3, 57, 2};
	int n = sizeof(arr) / sizeof(int);
	quicSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}