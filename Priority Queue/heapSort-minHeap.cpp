void haepSort(int arr[], int n)
{
	//building the min heap of array
	for (int i = 1; i < n; i++)
	{
		int childIndex = i;
		while (childIndex > 0)
		{
			int parentIndex = (childIndex - 1) / 2;
			if (arr[parentIndex] > arr[childIndex])
			{
				int temp = arr[childIndex];
				arr[parentIndex] = arr[childIndex];
				arr[childIndex] = temp;
			}
			else
				break;
			childIndex = parentIndex;
		}
	}

	//making heap sort by removing one by one min element
	int size = n;
	while (size > 1)
	{
		int temp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = temp;
		size--;

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;

		while (leftChildIndex < size)
		{
			int minIndex = parentIndex;
			if (arr[leftChildIndex] < arr[minIndex])
				minIndex = leftChildIndex;
			if (rightChildIndex < size && arr[rightChildIndex] < arr[minIndex])
				minIndex = rightChildIndex;
			if (minIndex == parentIndex)
				break;

			int temp = arr[minIndex];
			arr[minIndex] = arr[parentIndex];
			arr[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;
		}
	}
}