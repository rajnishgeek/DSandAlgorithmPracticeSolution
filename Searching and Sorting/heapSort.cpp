/* this is inplace min. heap sort which sort array in increasing order
   time complexity is O(nLog(n))
   space complexity is O(1)
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void buildMinHeap(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int child_index = i;
		while (child_index > 0)
		{
			int parent_index = (child_index - 1) / 2;
			if (arr[child_index] < arr[parent_index])
			{
				int temp = arr[child_index];
				arr[parent_index] = arr[child_index];
				arr[child_index] = temp;
			}
			else
				break;
			child_index = parent_index;
		}
	}
}

void removeMinHeapElement(int arr[], int size)
{
	int arr_size = size;
	while (arrsize > 1)
	{
		int temp = arr[0];
		arr[0] = arr[arr_size - 1];
		arr[arr_size - 1] = temp;
		arrsize--;

		int parent_index = 0;
		int left_child_index = 2 * parent_index + 1;
		int right_child_index = 2 * parent_index + 2;
		while (left_child_index < arr_size)
		{
			int min_index = parent_index;
			if (arr[left_child_index] < arr[parent_index])
				min_index = left_child_index;
			if (right_child_index < arr_size && arr[min_index] > arr[right_child_index])
				min_index = right_child_index;
			if (min_index == parent_index)
				break;

			int temp = arr[min_index];
			arr[min_index] = arr[parent_index];
			arr[parent_index] = temp;

			parent_index = min_index;
			left_child_index = 2 * parent_index + 1;
			right_child_index = 2 * parent_index + 2;
		}
	}
}
void inplaceMinHeapSort(int arr[], int size)
{
	buildMinHeap(arr, size);
	removeMinHeapElement(arr, size);
}
int main()
{
	int arr[] = {5, 7, 34, 65, 7, 83, 6};
	int size = sizeof(arr) / sizeof(int);
	InplaceMinHeapSort(arr, size);
	return 0;
}